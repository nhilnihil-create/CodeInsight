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

void func(long long N, long long K, std::string S){



    vector<lli> d;
    if(S[0]=='0')d.push_back(0);
    lli now=0;
    lli nex=1;
    while(now<N && nex<N){
        if(S[now]!=S[nex]){
            
            d.push_back(nex-now);
            now=nex;
        }
        nex++;
    }
    d.push_back(nex-now);
    if(S[N-1]=='0')d.push_back(0);

    lli ans = 0;
    lli sum = 0;
    REP(i,0,min((int)(2*K+1),(int)d.size())){
        sum+=d[i];
    }
    chmax(ans,sum);
    for(lli i=2*K+1;i<d.size();i+=2){
        LOG2(ans,sum);
        sum-=d[i-2*K-1];
        sum-=d[i-2*K];
        sum+=d[i];
        sum+=d[i+1];
        chmax(ans,sum);
    }

    cout<<ans<<endl;

}

int main(){
    // cout << fixed << setprecision(5);

    long long N;
    scanf("%lld",&N);
    long long K;
    scanf("%lld",&K);
    std::string S;
    std::cin >> S;
    func(N, K, S);
    return 0;
}
