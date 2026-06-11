#include <bits/stdc++.h>
using namespace std;

#define lli long long int
#define REP(i,s,n) for(int i=s;i<n;i++)
#define NUM 2520
#define INF (1LL<<62)
#define DEBUG 1
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

void func(long long N, long long K, std::vector<long long> x, std::vector<long long> y){

    vector<lli> xb(N),yb(N);
    REP(i,0,N){
        xb[i]=x[i];
        yb[i]=y[i];
    }

    SORT(xb);
    SORT(yb);

    lli ans =INF;

    REP(i,0,N)REP(j,i+1,N){
        lli x1 = xb[i];
        lli x2 = xb[j];
        REP(k,0,N)REP(l,k+1,N){
            lli y1 = yb[k];
            lli y2 = yb[l];

            lli cnt = 0;
            REP(m,0,N){
                if(x1<=x[m] && x[m]<=x2 && y1<=y[m] && y[m] <= y2)cnt++;
            }
            if(cnt>=K)chmin(ans,(x2-x1)*(y2-y1));
        }
    }

    cout<<ans<<endl;

}

int main(){
    // cout << fixed << setprecision(5);

    long long N;
    scanf("%lld",&N);
    long long K;
    scanf("%lld",&K);
    std::vector<long long> x(N);
    std::vector<long long> y(N);
    for(int i = 0 ; i < N ; i++){
        scanf("%lld",&x[i]);
        scanf("%lld",&y[i]);
    }
    func(N, K, std::move(x), std::move(y));
    return 0;
}
