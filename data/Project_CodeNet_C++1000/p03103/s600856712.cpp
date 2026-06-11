#include <bits/stdc++.h>
#define f(i,j,k) for(int i=j;i<k;i++)
#define f2(i,j,k) for(int i=j;i>k;i--)
using namespace std;
int main(){
    long long n,m,a,b,ans=0;
    cin>>n>>m;
    vector<pair<long long,long long>>c(n);
    f(i,0,n){
        cin>>a>>b;
        c[i]=make_pair(a,b);
    }
    sort(c.begin(),c.end());
    f(i,0,n){
        ans+=min(c[i].second,m)*c[i].first;
        m-=c[i].second;
        if(m<=0){
            break;
        }
    }
    cout<<ans<<endl;
    return 0;
}
