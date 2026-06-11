#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define f(i,j,n) for(int i=j;i<=n;i++)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s,c;
    cin>>s;
    int ans=1000000000;
    f(i,0,s.size()-1){
        c[0]=s[i];
        c[1]=s[i+1];
        c[2]=s[i+2];
        int k=stoi(c);
        ans=min(abs(k-753),ans);
    }
     cout<<ans;
}   
    
    
     

     
   



