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

map<lli,lli> makePrimeList2(lli n){
    map<lli,lli> m;
    lli a = 2;
    while(n>=a*a){
        if(n%a==0){
            m[a]++;
            n /= a;
        }
        else a++;
    }
    if(n!=1)m[n]++;
    return m;
}


int main(){

    lli n;
    cin>>n;

    lli ans = 0;
    REP(i,1,n+1){
        if(i%2==0)continue;
        map<lli,lli> prime = makePrimeList2(i);

        lli cnt = 1;
        for(auto e:prime){
            cnt *= (e.second+1);
        }
        LOG2(i,cnt);
        if(cnt==8)ans++;
    }

    cout<<ans<<endl;


    return 0;
}