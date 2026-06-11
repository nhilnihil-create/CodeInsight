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


void func(long long N, long long Z, long long W, std::vector<long long> a){
    if(N==1)cout<<abs(a[N-1]-W)<<endl;
    else cout<<max(abs(a[N-1]-W),abs(a[N-2]-a[N-1]))<<endl;

}

int main(){
    // cout << fixed << setprecision(5);

    long long N;
    scanf("%lld",&N);
    long long Z;
    scanf("%lld",&Z);
    long long W;
    scanf("%lld",&W);
    std::vector<long long> a(N);
    for(int i = 0 ; i < N ; i++){
        scanf("%lld",&a[i]);
    }
    func(N, Z, W, std::move(a));
    return 0;
}
