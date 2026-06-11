#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)
using namespace std;
using ll = long long;
int main(void){
    int N;
    cin>>N;
    int cnt=0,sp=0;
    rep(i,N){
        cnt=0;
        if((i+1)%2==0){
            continue;
        }
        rep(j,i+1){
            if((i+1)%(j+1)==0){
                cnt++;
            }
        }
        if(cnt==8){
            sp++;
        }
        
        
    }
    
    cout<<sp<<endl;
  
   
}