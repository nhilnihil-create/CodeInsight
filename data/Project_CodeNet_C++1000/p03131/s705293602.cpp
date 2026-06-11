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

void func(long long K, long long A, long long B){

    if(B-A<=2){
        cout<<K+1<<endl;
        return;
    }
    //両替する隙がない
    if(K-A<1){
        cout<<K+1<<endl;
        return;
    }

    lli lef = K-A+1;
    LOG(lef);
    lli ans = A + (B-A)*(lef/2);
    if(lef%2==1)ans++;
    cout<<ans<<endl;

}

int main(){
    // cout << fixed << setprecision(5);

    long long K;
    scanf("%lld",&K);
    long long A;
    scanf("%lld",&A);
    long long B;
    scanf("%lld",&B);
    func(K, A, B);
    return 0;
}
