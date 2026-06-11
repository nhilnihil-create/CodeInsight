#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define f(i,j,n) for(int i=j;i<=n;i++)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long n,s=0;
    cin>>n;
    long a[n];
    f(i,0,n-1){
       cin>>a[i];
       s+=a[i];
    }
    
    sort(a,a+n,greater<int>());
    
    cout<<s-a[0]/2;
}   
    
    
     

     
   



