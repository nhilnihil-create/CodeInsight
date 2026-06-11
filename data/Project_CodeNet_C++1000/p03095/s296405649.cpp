#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD=1000000007;
#define INF 1LL<<30
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define all(x) (x).begin(),(x).end()


ll num[30];
int main(){
    int n;
    string s;
    cin>>n>>s;

    rep(i,n) num[s[i]-'a']++;
    ll res=1;
    rep(i,26){
        res*=num[i]+1;
        res%=MOD;
    }

    cout<<res-1<<endl;
}
    


