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

lli f[110][10];
lli p[110][12];


int main(){

    lli N;
    cin>>N;
    REP(i,0,N){
        REP(j,0,10)cin>>f[i][j];
    }

    REP(i,0,N)REP(j,0,11)cin>>p[i][j];

    lli rtn = -INF;
    for(lli b=1;b<(1LL<<10);b++){
        lli ans = 0;

        REP(i,0,N){
            lli cnt = 0;
            REP(j,0,10){
                if(!(b&(1LL<<j)))continue;
                if(f[i][j]==0)continue;
                cnt++;
            }
            ans += p[i][cnt];
        }
        chmax(rtn,ans);
    }

    cout<<rtn<<endl;


    return 0;
}
