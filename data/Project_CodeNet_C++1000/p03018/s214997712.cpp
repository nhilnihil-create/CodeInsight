#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

const i64 MOD = 1e9 + 7;
const i64 INF = i64(1e18) + 7;

template <typename T>
bool chmin(T& x, T y){
    if(x > y){
        x = y;
        return true;
    }
    return false;
}

template <typename T>
bool chmax(T& x, T y){
    if(x < y){
        x = y;
        return true;
    }
    return false;
}

template <typename T>
struct BIT{
    vector<T> elm;
    BIT(int n, T init = T()) : elm(n + 1, init){
    }

    // [0, x)
    T sum(int x){
        T val = 0;
        for(; x > 0; x -= x & -x)
            val += elm[x];
        return val;
    }

    // [l, r)
    T sum(int l, int r){
        return sum(r) - sum(l);
    }

    void add(int x, T val){
        for(++x; x < elm.size(); x += x & -x)
            elm[x] += val;
    }
};


i64 solve(vector<int> v){
    BIT<int> b(v.size());
    for(int i = 0; i < v.size(); ++i)
        if(v[i] == 0)
            b.add(i, 1);
    i64 ans = 0;
    for(int i = 0; i < v.size(); ++i)
        if(v[i] == 1)
            ans += b.sum(i);
    return ans;
}

signed main(){
    string s;
    cin >> s;
    i64 ans = 0;
    vector<int> v;
    for(int i = 0; i < s.size(); ++i){
        if(s.substr(i, 2) == "BC"){
            v.push_back(1);
            ++i;
        }else if(s[i] == 'A')
            v.push_back(0);
        else
            v.push_back(-1);
    }
    v.push_back(-1);
    vector<int> w;
    for(auto& x : v){
        if(x == -1){
            if(!w.empty())
                ans += solve(w);
            w.clear();
        }else
            w.push_back(x);
    }
    cout << ans << endl;
}

