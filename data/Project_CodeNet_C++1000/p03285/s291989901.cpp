#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)
using namespace std;
using ll = long long;
int main(void){
    int N;
    cin>>N;
    bool exist=false;
    int p=N/4;
    if(N/4!=0){
        p++;
    }
    
    rep(x,p+1){
        rep(i,p+1){
            if(N==4*i+7*(x-i)){
                exist=true;
            }
        }
        
    }
    if(exist==true){
        cout<<"Yes"<<endl;
    }
    else{
        cout<<"No"<<endl;
    }
    
  
   
}