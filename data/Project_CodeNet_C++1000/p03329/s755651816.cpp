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
    int a[n+1];
    a[0]=0;
    rep(i,1,n+1){
        int x,y;
        y=1;
        x=1;
        a[i]=a[i-1]+1;
        rep(j,1,10){
            x=x*6;
            if(i-x<0)
            break;
            a[i]=min(a[i-x]+1,a[i]);
        }
        x=1;
        rep(j,1,10){
            x=x*9;
            if(i-x<0)
            break;
            a[i]=min(a[i-x]+1,a[i]);
        }
       
    }
    cout<<a[n]<<endl;
  
}
