#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define f(i,j,n) for(int i=j;i<=n;i++)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    cin>>s;
    f(i,0,s.size()-1){
        if(s[i]=='1')
          cout<<"9";
        else if(s[i]=='9')
          cout<<"1";
    }
}   
    
    
     

     
   



