#include <bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define rep(i,n)   FOR(i,0,n)
#define pb emplace_back
typedef long long ll;
typedef pair<int,int> pint;

int L;

int main(){
    cin>>L;
    int n=1;
    int cur=1;
    while(L>=cur*2) cur*=2,++n;
    int edcnt=0;
    vector<string> ans;
    rep(i,n-1){
        string t;
        t+=to_string(i+1)+" "+to_string(i+2)+" 0";
        ans.pb(t);
        t.clear();
        t+=to_string(i+1)+" "+to_string(i+2)+" "+to_string(1<<i);
        ans.pb(t);
    }
    for(int i=n-2;i>=0;--i){
        if(L-(1<<i)>=(1<<(n-1))){
            string t;
            t+=to_string(i+1)+" "+to_string(n)+" "+to_string(L-(1<<i));
            ans.pb(t);
            L-=(1<<i);
        }
    }
    cout<<n<<" "<<ans.size()<<endl;
    for(auto it:ans) cout<<it<<endl;
    return 0;
}