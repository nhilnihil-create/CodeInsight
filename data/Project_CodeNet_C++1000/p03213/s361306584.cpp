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

void func(long long N){

    map<lli,lli> dd;

    REP(i,2,N+1){
        map<lli,lli> ddd = makePrimeList2(i);
        for(auto e:ddd){
            dd[e.first] += e.second;
        }
    }

    lli ans = 0;

    lli tCnt=0,twCnt=0;
    lli fCnt=0;
    lli cnt14=0;
    //prime 75 only
    for(auto e:dd){
        LOG2(e.first,e.second);
        if(e.second>=74)ans++;
        
        if(e.second>=24)twCnt++;
        if(e.second>=14)cnt14++;
        if(e.second>=4)fCnt++;
        if(e.second>=2)tCnt++;
    }

    LOG3(twCnt,fCnt,tCnt);
    LOG(ans);

    //prime 24,2
    ans += (twCnt * (tCnt-1));

    LOG(ans);
    //prime 2,4,4
    ans += (fCnt*(fCnt-1)*(tCnt-2))/2;

    //prime 15,5
    ans += (cnt14*(fCnt-1));

    LOG(ans);
    cout<<ans<<endl;


}

int main(){
    // cout << fixed << setprecision(5);

    long long N;
    scanf("%lld",&N);
    func(N);
    return 0;
}
