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
template<typename A,typename B>inline void chmin(A &a,B b){if(a>b)a=b;}
template<typename A,typename B>inline void chmax(A &a,B b){if(a<b)a=b;}
int main()
{
    int N,M;
    cin >> N >> M;
    vll A(N);
    vector<pair<ll,ll>> B;
    cin >> A;
    REP(i,M){
        int b,c;
        cin >> b >> c;
        B.pb({c,b});
    }
    for(auto a : A){
        B.pb({a,1});
    }
    sort(B.begin(),B.end(),greater<pair<ll,ll>>());
    ll ans = 0;
    ll cnt = N;
    for(auto b : B){
        if(cnt > b.second){
            ans += b.first*b.second;
            cnt -= b.second;
        }else{
            ans += b.first*cnt;
            break;
        }
    }
    cout << ans << endl;

}