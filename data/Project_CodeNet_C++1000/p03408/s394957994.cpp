#include <bits/stdc++.h>
#define f(i,j,k) for(int i=j;i<k;i++)
#define f2(i,j,k) for(int i=j;i>k;i--)
using namespace std;
int main(){
    long long n,m,ans=0;
    cin>>n;
    string s;
    map<string,long long> a;
    f(i,0,n){
        cin>>s;
        a[s]++;
    }
    cin>>m;
    f(i,0,m){
        cin>>s;
        a[s]--;
    }
    for(auto x:a){
        ans=max(ans,x.second);
    }
    cout<<ans<<endl;
    return 0;
}
