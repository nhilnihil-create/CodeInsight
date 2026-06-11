#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD=1000000007;
#define INF 1LL<<30
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define all(x) (x).begin(),(x).end()

int main(){
    int n;
    cin>>n;

    string ans="";
    while(n!=0){
        int r=n%2;
        if(r<0) r+=2;
        ans+=char(r+'0');
        n=(n-r)/(-2);
    }
    
    reverse(all(ans));
    if(ans=="") ans="0";
    cout<<ans<<endl;
}