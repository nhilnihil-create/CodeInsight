#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
//#define MOD 998244353
#define INF 1145141919810893364
typedef pair<int,int> PP;
typedef long long ll;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
#define int ll
#define setdouble setprecision
#define REP(i,n) for(int i=0;i<(n);++i)
#define OREP(i,n) for(int i=1;i<=(n);++i)
#define RREP(i,n) for(int i=(n)-1;i>=0;--i)
#define GOODBYE cout << -1 << endl;return 0
#define MM <<" "<<
#define Endl endl


signed main(void){
    int N,K,Q;
    int A[2019];
    cin >> N >> K >> Q;
    REP(i,N){
        cin >> A[i];
    }
    
    vector<pair<int,int>> c;
    vector<int> q;
    int Ans=INF;
    REP(z,N){
        int LEV=A[z];
        int e[2019]={};
        c.clear();
        q.clear();
        REP(i,N+1){
            if(i==N || A[i]<LEV){
                sort(c.begin(),c.end());
                int m=c.size();
                REP(j,m-K+1){
                    e[c[j].second]=1;
                }
                c.clear();
            }else{
                c.push_back({A[i],i});
            }
        }
        REP(i,N){
            if(e[i]!=0){
                q.push_back(A[i]);
            }
        }
        sort(q.begin(),q.end());
        int p=q.size();
        if(p<Q)continue;
        Ans=min(Ans,q[Q-1]-LEV);
        
    }
    cout << Ans << endl;
    return 0;
}

