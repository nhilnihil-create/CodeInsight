#include <bits/stdc++.h>
using namespace std;
#define rep(i, srt, end) for (long long i = (srt); i < (long long)(end); i++)
#define VL vector<ll>
#define INF 100000000
typedef long long ll;

int main(){
    string S;
    cin>>S;
    ll ans=0;
    rep(i,0,4){
        if(S[i]=='+')ans++;
        if(S[i]=='-')ans--;
    }
    cout<<ans;
    
    return 0;
}