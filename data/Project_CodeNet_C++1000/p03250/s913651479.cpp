#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define f(i,j,n) for(int i=j;i<=n;i++)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int a[3];
    cin>>a[0]>>a[1]>>a[2];
    sort(a,a+3,greater<int>());
    cout<<(a[0]*10+a[1])+a[2];
    
    
}   
    
    
     

     
   



