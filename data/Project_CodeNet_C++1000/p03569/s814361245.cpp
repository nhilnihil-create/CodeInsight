#include <bits/stdc++.h>

using namespace std;
#define all(a)a.begin(),a.end()
#define rep(i,n) for (int i = 0; i < (n); ++i)
using ll=long long;
using ll=long long;
const int INF = 1<<30;
const ll INFll =1LL<<62;
const int mod = int(1e9)+7;
using V = vector<ll>;
using P = pair<ll,ll>;

int main()
{
   string s;cin >>s;
   ll l=0,r=s.size()-1;
   ll ans=0;
   while(1){
    if(l>=r)break;
    if(s[l]==s[r]){
            l++;r--;
    }
    else if(s[l]=='x'){
        ans++;
        l++;
    }
    else if(s[r]=='x'){
        ans++;
        r--;
    }
    else{
        ans=-1;
        break;
    }
   }
   cout << ans << endl;
    return 0;
}
