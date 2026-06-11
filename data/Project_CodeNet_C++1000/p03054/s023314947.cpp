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

void func(long long H, long long W, long long N, long long s_r, long long s_c, std::string S, std::string T){

    s_r--,s_c--;
    lli l = -1, r = W;
    for(lli i=N-1;i>=0;i--){
        LOG3(i,l,r);
        //青木君落とされたくいない
        if(T[i]=='R')l = max(l-1,-1LL);
        if(T[i]=='L')r = min(r+1,W);

        //高橋君落としたい
        if(S[i]=='R')r = max(r-1,-1LL);
        if(S[i]=='L')l = min(l+1,W);

        if(r<=l+1){
            cout<<NO<<endl;
            return;
        }
    }
    LOG2(l,r);
    if(s_c<=l || r<=s_c){
        cout<<NO<<endl;
        return;
    }

    l = -1, r = H;
    for(lli i=N-1;i>=0;i--){
            
        //青木君落とされたくいない
        if(T[i]=='D')l = max(l-1,-1LL);
        if(T[i]=='U')r = min(r+1,H);

        //高橋君落としたい
        if(S[i]=='D')r = max(r-1,-1LL);
        if(S[i]=='U')l = min(l+1,H);

        if(r<=l+1){
            cout<<NO<<endl;
            return;
        }
    }
    if(s_r<=l || r<=s_r){
        cout<<NO<<endl;
        return;
    }

    cout<<YES<<endl;

}

int main(){
    // cout << fixed << setprecision(5);

    long long H;
    scanf("%lld",&H);
    long long W;
    scanf("%lld",&W);
    long long N;
    scanf("%lld",&N);
    long long s_r;
    scanf("%lld",&s_r);
    long long s_c;
    scanf("%lld",&s_c);
    std::string S;
    std::cin >> S;
    std::string T;
    std::cin >> T;
    func(H, W, N, s_r, s_c, S, T);
    return 0;
}
