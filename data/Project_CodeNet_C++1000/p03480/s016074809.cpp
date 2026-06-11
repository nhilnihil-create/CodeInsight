#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define For(i,n,k) for(ll i=(n);i<(k);i++)
ll n,m,ans=1;
string s;
bool flag;
void Main(){    
    cin>>s;
    n=s.size();
    ans=n;
    For(i,1,n){
        if(s.at(i)!=s.at(i-1)){
            ans=min(ans,max(i,n-i));
        }
    }
    cout<<ans<<endl;
}
int main(){
    Main();
    return 0;
}
