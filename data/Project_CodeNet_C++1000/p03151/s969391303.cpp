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
    int N;
    cin >> N;
    vll A(N),B(N);
    cin >> A >> B;
    vll H;
    int L = 0;
    ll Lcnt = 0;
    REP(i,N){
        if(A[i] >= B[i]){
            H.pb(A[i]-B[i]);
        }else{
            Lcnt += B[i]-A[i];
            L++;
        }
    }
    
    sort(H.begin(),H.end(),greater<ll>());
    int ans = 0;
    if(H.size() != N){
        ll cnt = 0;
        bool flag = false;
        REP(i,H.size()){
            cnt += H[i];
            ans++;
            if(cnt >= Lcnt){
                ans += L;
                flag = true;
                break;
            }
        }
        if(!flag)ans = -1;
    }
    cout << ans << endl;
}