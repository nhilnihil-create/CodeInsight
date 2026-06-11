#include <iostream>
#include <vector>
#include <set>
using namespace std;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
 
int main() {
    long long N;
    cin >> N;
    string S;
    cin >> S;
    long long ans = 3000000;
    vector<long long> WCL(N+1);
    vector<long long> ECL(N+1);
    WCL[0] = 0;
    ECL[0] = 0;
    rep(i, 1, N+1){
        ECL[i]=ECL[i-1];
        WCL[i]=WCL[i-1];
        if(S[i-1]=='E') ECL[i]++;
        else WCL[i]++;
    }
    for(int i=1;i<=N;i++){
      ans=min(ans,WCL[i-1]+(ECL[N]-ECL[i]));
    }
       cout<<ans<<endl;
}
