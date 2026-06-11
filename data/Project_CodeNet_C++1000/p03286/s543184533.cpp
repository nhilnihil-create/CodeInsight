#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD=1000000007;
#define INF 1LL<<30
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define all(x) (x).begin(),(x).end()

int main(){
    ll n;
    cin>>n;

    string ans="";
    ll base=1;
    while(n!=0){
        if(n%(base*2)==0) ans+='0';
        else{
            ans+='1';
            n-=base;
        }
        base*=-2;
    }
    
    reverse(all(ans));
    if(ans=="") ans="0";
    cout<<ans<<endl;
}