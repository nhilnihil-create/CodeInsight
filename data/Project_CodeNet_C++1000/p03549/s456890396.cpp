#include <bits/stdc++.h>
using namespace std;

#define lli long long int
#define REP(i,s,n) for(int i=s;i<n;i++)
#define MOD 1000000007
#define NUM 2520
#define INF (1LL<<50)
#define DEBUG 0
#define mp(a,b) make_pair(a,b)
#define SORT(V) sort(V.begin(),V.end())
#define PI (3.141592653589794)


void func(long long N, long long M){
    lli ans = 1900*M+100*(N-M);
    REP(i,0,M)ans*=2;
    cout<<ans<<endl;
}

int main(){
    // cout << fixed << setprecision(5);

    long long N;
    scanf("%lld",&N);
    long long M;
    scanf("%lld",&M);
    func(N, M);
    return 0;
}
