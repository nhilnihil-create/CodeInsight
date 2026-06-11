#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD=1e9+7;
const int INF=1e9;

int main(){
    string s; cin>>s;
    int n=s.size();
    int ans,m=n/2,l,r;
    if(n&1){
        l=m-1;
        r=m+1;
        ans=m+1;
    }
    else{
        l=m-1;
        r=m;
        ans=m;
    }
    while(0<=l){
        if(s[m]==s[l--]&&s[m]==s[r++]){
            ans++;
        }
        else break;
    }
    cout<<ans<<endl;
}
