#include <bits/stdc++.h>
using namespace std;

int main(){
    int a,b,c;
    long long ans=0;
    cin >>a>>b>>c;

    ans=min(c,b)*2;
    if(b >c){
  
        b=b-c;
        c = 0;
    }else{
        c=c-b;
        b=0;
    }

    
    
               // cout <<ans<<endl;

                //cout <<b<<" "<<c<<endl;
    ans=ans+min(a+1,c)+b;

    cout <<ans<<endl;

   
       
   
}
