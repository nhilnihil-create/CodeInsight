#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> Pii;
typedef pair<ll,ll> Pll;
#define rep(i,n) for (ll i=0;i<n;++i)
#define rep2(i,a,b) for (ll i=a;i<b;++i)
const ll MOD=1000000007;
string alp="abcdefghijklmnopqrstuvwxyz";

int main(){
    string S;
    cin >> S;
    int s=S.size(),ans=1;
    vector<int> count(s+1);
    count[0]=0;
    rep(i,s){
        count[i+1]=count[i];
        if (S[i]=='1'){
            count[i+1]++;
        }
    }
    rep(i,s){
        int c=count[s-i]-count[i];
        if (c==s-2*i||c==0){
            ans=s-i;
            break;
        }
    }
    cout << ans << endl;
}