#include <bits/stdc++.h>
using namespace std;

#define lli long long int
#define REP(i,s,n) for(int i=s;i<n;i++)
#define NUM 2520
#define INF (1LL<<50)
#define DEBUG 0
#define mp(a,b) make_pair(a,b)
#define SORT(V) sort(V.begin(),V.end())
#define PI (3.141592653589794)
#define TO_STRING(VariableName) # VariableName
#define LOG(x) if(DEBUG)cout<<TO_STRING(x)<<"="<<x<<" "<<endl;
#define LOG2(x,y) if(DEBUG)cout<<TO_STRING(x)<<"="<<x<<" "<<TO_STRING(y)<<"="<<y<<endl;
#define LOG3(x,y,z) if(DEBUG)cout<<TO_STRING(x)<<"="<<x<<" "<<TO_STRING(y)<<"="<<y<<" "<<TO_STRING(z)<<"="<<z<<endl;
#define LOG4(w,x,y,z) if(DEBUG)cout<<TO_STRING(w)<<"="<<w<<" "<<TO_STRING(x)<<"="<<x<<" "<<TO_STRING(y)<<"="<<y<<" "<<TO_STRING(z)<<"="<<z<<endl;

template<class T>bool chmax(T & a, const T & b) { if (a < b) { a = b; return 1; } return 0; }
template<class T>bool chmin(T& a, const T& b) { if (b < a) { a = b; return 1; } return 0; }


int main(){
    // cout << fixed << setprecision(5);

    long long N;
    scanf("%lld",&N);
    long long K;
    scanf("%lld",&K);
    long long Q;
    scanf("%lld",&Q);
    std::vector<long long> A(N);
    for(int i = 0 ; i < N ; i++){
        scanf("%lld",&A[i]);
    }

    lli ans = INF;
    REP(i,0,N){
        vector<lli> P,V;
        REP(j,0,N){
            if(A[j]<A[i]){
                if(V.size()>=K){
                    SORT(V);
                    REP(x,0,V.size()-K+1)P.push_back(V[x]);
                }
                V.clear();
            }
            else{
                V.push_back(A[j]);
            }
        }
        if(V.size()>=K){
            SORT(V);
            REP(x,0,V.size()-K+1)P.push_back(V[x]);
        }
        if(P.size()<Q)continue;
        SORT(P);
        chmin(ans,P[Q-1]-P[0]);
    }

    cout<<ans<<endl;


    return 0;
}
