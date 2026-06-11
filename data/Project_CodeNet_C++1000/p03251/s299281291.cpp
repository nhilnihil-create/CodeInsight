#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define f(i,j,n) for(int i=j;i<=n;i++)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m;
    cin>>n>>m;
    
    int a[n],b[m];
    cin>>a[0]>>b[0];
    f(i,1,n)
      cin>>a[i];
    
sort(a,a+n+1); 
    
    f(i,1,m)
      cin>>b[i];
      
sort(b,b+m+1);
    
    if(b[0]-(a[n]+1)>=0)
      cout<<"No War";
    else 
     cout<<"War";
} 