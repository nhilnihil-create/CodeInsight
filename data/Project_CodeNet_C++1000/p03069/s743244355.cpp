#include <bits//stdc++.h>
using namespace std;
#define rep(i,n,k) for(int i=n;i<k;i++)
#define int  long long
#define F first 
#define S second
#define P make_pair 
struct Runrun{
    vector<int> r;
};

signed main(void){
 
    
    int n,m,q,p,r,ans,t;
    string s;
    vector<int> v;
    ans=0;
    cin>>n;
    cin>>s;
    m=0;
    rep(i,0,n){
        if(s[i]=='.'){
        m++;
        }
    }
    ans=m;
    rep(i,0,n){
        if(s[i]=='.')
        m--;
        else
        m++;
        ans=min(ans,m);
    }
    cout<<ans<<endl;
  
}
