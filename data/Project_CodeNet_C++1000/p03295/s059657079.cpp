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
#define LOG(x) if(DEBUG)cout<<TO_STRING(x)<<"="<<x<<" ";
#define LOGE if(DEBUG)cout<<endl;

template<class T>bool chmax(T & a, const T & b) { if (a < b) { a = b; return 1; } return 0; }
template<class T>bool chmin(T& a, const T& b) { if (b < a) { a = b; return 1; } return 0; }

void func(long long N, long long M, std::vector<long long> a, std::vector<long long> b){

    vector<pair<lli,lli>> v;
    REP(i,0,M){
        v.push_back({b[i],a[i]});
    }
    sort(v.begin(),v.end());

    set<lli> t;

    lli now=-INF;
    lli ans=0;
    REP(i,0,M){
        if(now<=v[i].second){
            now=v[i].first;
            ans++;
        }
    }
    cout<<ans<<endl;

}

int main(){
    // cout << fixed << setprecision(5);

    long long N;
    scanf("%lld",&N);
    long long M;
    scanf("%lld",&M);
    std::vector<long long> a(M);
    std::vector<long long> b(M);
    for(int i = 0 ; i < M ; i++){
        scanf("%lld",&a[i]);
        scanf("%lld",&b[i]);
    }
    func(N, M, std::move(a), std::move(b));
    return 0;
}
