#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define f(i,j,n)  for(int i=j;i<=n;i++)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,k=0,s=0;
    cin>>n;
    int a[n];
    f(i,0,n-1)
      {cin>>a[i];}
      
    sort(a,a+n,greater<int>());
    
    f(i,0,n-1)
    { if((i+1)%2==0)
       s=s+a[i];
     else
       k=k+a[i];
    }   
    cout<<k-s;
}   
    
    
     

     
   



