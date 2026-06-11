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

//i個使ったときの最高のスコア
lli dp[1020];

void func(long long D, long long G, std::vector<long long> p, std::vector<long long> c){

    REP(i,0,1020)dp[i]=-INF;
    dp[0]=0;
    REP(i,0,D){
        vector<lli> nextDp(1020,-INF);
        nextDp[0]=0;
        REP(j,1,p[i]+1){
            REP(k,0,1020){
                if(dp[k]<0)continue;
                if(j+k>=1020)continue;
                lli score = (i+1)*j;
                if(j==p[i])score += c[i];
                chmax(nextDp[j+k],dp[k]+score);
            }
        }

        REP(j,0,1020)chmax(dp[j],nextDp[j]);
    }
    REP(i,0,1020){
        if(dp[i]>=G){
            cout<<i<<endl;
            return;
        }
    }
}

int main(){
    // cout << fixed << setprecision(5);

    long long D;
    scanf("%lld",&D);
    long long G;
    scanf("%lld",&G);
    std::vector<long long> p(D);
    std::vector<long long> c(D);
    for(int i = 0 ; i < D ; i++){
        scanf("%lld",&p[i]);
        scanf("%lld",&c[i]);
        c[i]/=100;
    }
    G/=100;
    func(D, G, std::move(p), std::move(c));
    return 0;
}
