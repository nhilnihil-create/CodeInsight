#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define f(i,j,n) for(int i=j;i<=n;i++)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long n,t,k=0,y=100001;
    cin>>n>>t;
    f(i,1,n){
        long a=0,b=0;
        cin>>a>>b;
        if(b<=t){
            {k++;y=min(a,y);}
        }
    }
    if(k>0)
      cout<<y;
    else 
      cout<<"TLE";
}   
    
    
     

     
   



