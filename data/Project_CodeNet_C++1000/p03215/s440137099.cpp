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

void func(long long N, long long K, std::vector<long long> a){

    vector<lli> d;
    vector<lli> sum(N+1);
    sum[0]=0;
    REP(i,0,N)sum[i+1] = sum[i]+a[i];

    REP(i,0,N){
        REP(j,i+1,N+1){
            d.push_back(sum[j]-sum[i]);
        }
    }
    sort(d.rbegin(),d.rend());
    vector<bool> flag(d.size(),true);

    bool j = false;

    lli ans = 0;
    for(lli bit=62;bit>=0;bit--){
        
        lli cnt = 0;
        REP(i,0,d.size()){
            if(!flag[i])continue;
            if(d[i]&(1LL<<bit))cnt++;
        }
        if(cnt<K)continue;

        REP(i,0,d.size()){
            if(!(d[i]&(1LL<<bit)))flag[i]=false;
        }
        ans |= (1LL<<bit);
    }


    cout<<ans<<endl;

}

int main(){
    // cout << fixed << setprecision(5);

    long long N;
    scanf("%lld",&N);
    long long K;
    scanf("%lld",&K);
    std::vector<long long> a(N);
    for(int i = 0 ; i < N ; i++){
        scanf("%lld",&a[i]);
    }
    func(N, K, std::move(a));
    return 0;
}
