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



void func(long long N, long long K, long long Q, std::vector<long long> A){

    lli ans = INF;
    REP(i,0,N){
        vector<lli> v,p;
        REP(j,0,N){
            if(A[j]<A[i]){
                if(v.size()>=K){
                    SORT(v);
                    REP(x,0,v.size()-K+1)p.push_back(v[x]);
                }
                v.clear();
            }
            else{
                v.push_back(A[j]);
            }
        }
        if(v.size()>=K){
            SORT(v);
            REP(x,0,v.size()-K+1)p.push_back(v[x]);
        }
        SORT(p);
        if(p.size()>=Q)chmin(ans,p[Q-1]-p[0]);
    }
    cout<<ans<<endl;

}

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
    func(N, K, Q, std::move(A));
    return 0;
}
