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


const string YES = "YES";
const string NO = "NO";

map<lli,lli> cnts;

void func(long long N, std::vector<long long> D, long long M, std::vector<long long> T){

    REP(i,0,N){
        cnts[D[i]]++;
    }

    REP(i,0,M){
        if(cnts[T[i]]==0){
            cout<<NO<<endl;
            return;
        }
        cnts[T[i]]--;
    }

    cout<<YES<<endl;

}

int main(){
    // cout << fixed << setprecision(5);

    long long N;
    scanf("%lld",&N);
    std::vector<long long> D(N);
    for(int i = 0 ; i < N ; i++){
        scanf("%lld",&D[i]);
    }
    long long M;
    scanf("%lld",&M);
    std::vector<long long> T(M);
    for(int i = 0 ; i < M ; i++){
        scanf("%lld",&T[i]);
    }
    func(N, std::move(D), M, std::move(T));
    return 0;
}
