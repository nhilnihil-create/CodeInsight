#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using Graph = vector<vector<int>>;
#define ALL(x) (x).begin(), (x).end()
#define REP(i ,n) for(int i = 0; i < (int)(n); i++)
#define pb push_back
typedef vector<int>vint;
typedef vector<ll>vll;
template<typename T> istream &operator>>(istream &is, vector<T> &vec){ for (auto &v : vec) is >> v; return is; }
template<typename A,typename B>inline bool chmin(A &a,const B &b){if(a>b){a=b;return true;}else{return false;}}
template<typename A,typename B>inline bool chmax(A &a,const B &b){if(a<b){a=b;return true;}else{return false;}}

int main()
{
    ll K,A,B;
    cin >> K >> A >> B;
    ll ans = 0;
    if((K <= A) || ((B-A)<=2)){
        ans = K + 1;
    }else{
        ll L = (K-A+1)/2;
        ll M = (K-A+1)%2;
        ans += L*(B-A) + M + A;
    }
    cout << ans << endl;
}