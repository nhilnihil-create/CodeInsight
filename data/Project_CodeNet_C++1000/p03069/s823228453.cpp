#include<iostream>
#include<string>
#include<vector>
#include<iomanip>
#include<algorithm>
#include<queue>
#include<stack>
#include<list>
#include<map>
#include<deque>
#include<math.h>
using namespace std;
#define ll long long
int main(){
    ll N;
    string S;
    cin >> N >> S;
    ll i;
    ll w[N+1],b[N+1];
    w[0]=0;b[0]=0;
    for(i=0;i<N;i++){
        if(S[i]=='#')w[i+1]=w[i]+1;else w[i+1]=w[i];
        if(S[N-i-1]=='.')b[i+1]=b[i]+1;else b[i+1]=b[i];
    }
    ll ans=N;
    for(i=0;i<N+1;i++){
        ans=min(ans,w[i]+b[N-i]);
    }
    cout << ans <<endl;
    return 0;
}
