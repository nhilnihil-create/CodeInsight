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
    if(S[0]=='o')ans++;
    if(S[1]=='o')ans++;
    if(S[2]=='o')ans++;
    cout<<700+ans*100;
    return 0;
}