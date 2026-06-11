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
    int N,Q;
    cin >> N >> Q;
    string S;
    cin >> S;
    vint cnt(N);
    for(int i=1; i<N; i++){
        if('A' == S[i-1] && 'C' == S[i]){
            cnt[i] = cnt[i-1]+1;
        }else{
            cnt[i] = cnt[i-1];
        }
    }
    vint ans;
    REP(i,Q){
        int a,b;
        cin >> a >> b;
        a--;
        b--;
        ans.pb(cnt[b]-cnt[a]);
    }
    for(auto a:ans){
        cout << a << endl;
    }
}