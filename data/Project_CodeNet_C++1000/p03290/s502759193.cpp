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

void func(long long D, long long G, std::vector<long long> p, std::vector<long long> c){

    lli ans = INF;
    for(lli bit=0;bit<(1LL<<D);bit++){
        //prepare
        lli score = 0;
        lli cnt = 0;
        REP(i,0,D){
            if(!(bit&(1LL<<i)))continue;
            score += (i+1)*100*p[i] + c[i];
            cnt += p[i];
        }

        if(score >= G){
            chmin(ans,cnt);
            continue;
        }

        for(lli i = D-1;i>=0;i--){
            if((bit&(1LL<<i)))continue;
            lli left = max(0LL,G-score);
            if(left > (i+1)*100*p[i]){
                score += (i+1)*100*p[i]+c[i];
                cnt += p[i];
            }
            else{
                lli plusC = (left)/((i+1)*100);
                if((left%(100*(i+1)))!=0)plusC++;
                cnt += plusC;
                break;
            }
        }
        chmin(ans,cnt);
    }

    cout<<ans<<endl;

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
    }
    func(D, G, std::move(p), std::move(c));
    return 0;
}
