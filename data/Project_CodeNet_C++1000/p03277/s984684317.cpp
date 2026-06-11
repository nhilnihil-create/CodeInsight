#include <algorithm>
#include <bitset>
#include <cassert>
#include <chrono>
#include <climits>
#include <cmath>
#include <complex>
#include <cstring>
#include <deque>
#include <functional>
#include <iostream>
#include <iomanip>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <cstdint>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;
#define MP make_pair
#define PB push_back
#define inf 1000000007
#define rep(i,n) for(int i = 0; i < (int)(n); ++i)
#define all(x) (x).begin(),(x).end()

template<typename A, size_t N, typename T>
void Fill(A (&array)[N], const T &val){
    std::fill( (T*)array, (T*)(array+N), val );
}
 
template<class T> inline bool chmax(T &a, T b){
    if(a<b){
        a = b;
        return true;
    }
    return false;
}

template<class T> inline bool chmin(T &a, T b){
    if(a>b){
        a = b;
        return true;
    }
    return false;
}


template<typename T> class BIT {
private:
	int n;
	vector<T> bit;
public:
	// 0_indexed で i 番目の要素に x を加える
	void add(int i, T x){
		i++;
		while(i < n){
			bit[i] += x, i += i & -i;
		}
	}
	// 0_indexed で [0,i] の要素の和(両閉区間！！)
	T sum(int i){
		i++;
		T s = 0;
		while(i > 0){
			s += bit[i], i -= i & -i;
		}
		return s;
	}
	BIT(){}
	//初期値がすべて0の場合
	BIT(int sz) : n(sz+1), bit(n, 0){}
	BIT(vector<T>& v) : n((int)v.size()+1), bit(n, 0){
		for(int i = 0; i < n-1; i++){
			add(i,v[i]);
		}
	}
	void print(){
		for(int i = 0; i < n-1; i++){
			cout<<sum(i)-sum(i-1)<< " ";
		}
		cout<<endl;
	}
	//-1スタート
	void print_sum(){
		for(int i = 0; i < n; i++){
			cout<<sum(i-1)<<" ";
		}
		cout<<endl;
	}
};

ll n;
ll m;
vector<int> a;

bool up(int x){
    vector<int> b(n+1);
    rep(i,n){
        if(a[i]>=x){
            b[i+1] = 1;
        }else{
            b[i+1] = -1;
        }
    }
    for(int i=1;i<=n;i++){
        b[i] += b[i-1];
    }
    rep(i,n+1){
        b[i] += n;
    }
    BIT<ll> bit(2*n+2);
    rep(i,n+1){
        bit.add(b[i],1);
    }
    ll tmp = 0;
    rep(i,n+1){
        tmp += bit.sum(2*n+1) - bit.sum(b[i]-1)-1;
        bit.add(b[i],-1);
    }
    // cerr << x << " " << tmp << endl;
    return (tmp >=m&&tmp!=0);
}
int main(){
    cin >> n; 
    a.resize(n);
    rep(i,n){
        cin >> a[i];
    }   
    m = n*(n+1)/2;
    m = m/2;
    int ok = 1;
    int ng = 1000000001;
    while(ng-ok>1){
        int mid = (ok+ng)/2;
        if(up(mid)){
            ok = mid;
        }else{
            ng = mid;
        }
    }
    cout << ok << endl;
    return 0;
}