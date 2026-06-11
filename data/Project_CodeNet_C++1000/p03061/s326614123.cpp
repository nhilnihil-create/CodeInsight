#include<bits/stdc++.h>
using namespace std;
using ll = long long;



template<class M> class SegmentTree {
public:
    using T = typename M::value_type;
private:
    int m;
    int n;
    vector<T> data;
public:
    SegmentTree(const vector<T>& a) {
        m = a.size();
        for(n = 1; n < (int)a.size(); n <<= 1);
        data.resize(n<<1, M::id);
        for(int i = 0; i < (int)a.size(); i++)data[i + n] = a[i];
        for(int i = n - 1; i >= 1; i--) data[i] = M::op(data[i<<1], data[(i<<1) + 1]);
    }

    T get(int l, int r) {
        if(l == r)return M::id;
        l += n, r += n;
        ll vl = M::id, vr = M::id;
        while(l < r) {
            if(l & 1) {
                vl = M::op(vl, data[l]);
                l++;
            }
            if(r & 1) {
                r--;
                vr = M::op(data[r], vr);
            }
            l >>= 1, r>>=1;
        }
        return M::op(vl, vr);
    }

    void assign(int index, T val) {
        index += n;
        data[index] = val;
        while(index != 1){
            index >>= 1;
            data[index] = M::op(data[index<<1], data[(index<<1) + 1]);
        }
    }

    T operator[] (int i){
        return data[i + n];
    }

};

template<class T> class Plus {
public:
    using value_type = T;
    static T op(T l, T r) {return l + r;}
    static constexpr T id = 0;
};

template<class T> class Min {
public:
    using value_type = T;
    static T op(T l, T r) {return min(l, r);}
    static constexpr T id = 1e9;
};

template<class T> class Max {
public:
    using value_type = T;
    static T op(T l, T r) {return max(l, r);}
    static constexpr T id = -1e9;
};

template<class T> class Gcd {
public:
    using value_type = T;
    static T op(T l, T r) {return __gcd(l, r);}
    static constexpr T id = 0;
};

int main()
{
	int n; cin >> n;
	vector<int> a(n);
	for(int i = 0; i < n; i++) cin >> a[i];
	SegmentTree<Gcd<int>> tree(a);
	int nax = 0;
	for(int i = 0; i < n; i++) {
		tree.assign(i, 0);
		nax = max(nax, tree.get(0, n));
		tree.assign(i, a[i]);
	}
	cout << nax << endl;
}