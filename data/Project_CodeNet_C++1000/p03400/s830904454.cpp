#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define f(i,j,n) for(int i=j;i<=n;i++)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,d,k=0,l;
    cin>>n>>d>>l;
    f(i,1,n)
     { int a;
       cin>>a;
       k+=(d+a-1)/a;
    }
    cout<<k+l;
}   
    
    
     

     
   



