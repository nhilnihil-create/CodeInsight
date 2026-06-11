#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define f(i,j,n) for(int i=j;i<=n;i++)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int a,b;
   cin>>a>>b;
   int c=a*b;
   if(1*c%2!=0 || 2*c%2!=0 || 3*c%2!=0 )
    cout<<"Yes";
   else 
    cout<<"No";
} 