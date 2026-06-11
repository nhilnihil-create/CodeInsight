#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;
const ll MOD=pow(10,9)+7;
const ll INF=(1LL<<62);
const int dx[4]={0,1,0,-1};
const int dy[4]={1,0,-1,0};
const int ddx[8]={1,0,-1,-1,-1,0,1,1};
const int ddy[8]={1,1,1,0,-1,-1,-1,0};
void init(){
}
int main(){
    string s,ans;cin>>s;
    ll w;cin>>w;
    for (int i = 0; i < s.size(); i+=w)
    {
        ans.push_back(s[i]);
    }
    
    cout<<ans<<endl;
}