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
    vector<vector<int>> S(M,vector<int>(N,0));
    vector<int> P(M);
    REP(m,M){
        int K;
        int s;
        cin >> K;
        REP(k,K){
            cin >> s;
            s--;
            S[m][s] = 1;
        }
    }
    cin >> P;
    int ans = 0;
    for(int bit=0; bit<(1<<N); bit++){
        int p_cnt = 0;
        REP(m,M){
            int cnt = 0;
            for(int i=0;i<N;i++){
                if((bit&(1<<i)) && (1 == S[m][i])){
                    cnt++;
                }
            }
            if(P[m] == cnt%2){
                p_cnt++;
            }
        }
        if(M == p_cnt)ans++;
    }
    cout << ans << endl;
}