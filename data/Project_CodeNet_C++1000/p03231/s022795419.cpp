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
    ll N,M;
    cin >> N >> M;
    string S,T;
    cin >> S >> T;
    ll L = N*M/__gcd(N,M);
    ll stepN,stepM;
    stepN = L/N;
    stepM = L/M;
    for(int i=0; i<M; i++){
        if(0 == (i*stepM)%stepN){
            int idxN = (i*stepM)/stepN;
            if(idxN >= N){
                break;
            }
            if(S[idxN] != T[i]){
                L = -1;
                break;
            }
        }
    }
    cout << L << endl;
}