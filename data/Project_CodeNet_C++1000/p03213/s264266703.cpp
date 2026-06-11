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

map<lli,lli> cnt;

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

    REP(i,1,N+1){
        map<lli,lli> prime = makePrimeList2(i);
        for(auto e:prime){
            cnt[e.first]+=e.second;
        }
    }
    //約数が75個,-> x^2*y^24 or x^2*y^4*z^4 or x^4 or y^15 ,x^74

    lli sum = 0;
    //x^2,y^24の組み合わせ
    lli x = 0,y=0;
    for(auto e:cnt){
        if(e.second>=2)x++;
        if(e.second>=24)y++;
    }
    sum += y*(x-1);

    //x^2*y^4*z^4の組み合わせ
    x=0,y=0;
    for(auto e:cnt){
        if(e.second>=2)x++;
        if(e.second>=4)y++;
    }
    sum += y*(y-1)/2*(x-2);

    //x^4*y^14
    x=0,y=0;
    for(auto e:cnt){
        if(e.second>=4)x++;
        if(e.second>=14)y++;
    }
    sum += y*(x-1);

    x=0;
    for(auto e:cnt){
        if(e.second>=74)x++;
    }

    sum+=x;

    cout<<sum<<endl;

}

int main(){
    // cout << fixed << setprecision(5);

    long long N;
    scanf("%lld",&N);
    func(N);
    return 0;
}
