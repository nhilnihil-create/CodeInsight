#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)
using namespace std;
using ll = long long;
int main(void){
    string S;
    cin>>S;
    int cnt=0;
    int len=S.size();
    bool AC=true;
  
    if(S[0]!='A'){
        AC=false;
    }
    for(int i=2;i<len-1;i++){
        if(S[i]=='C'){
            cnt++;
            
        }
    }
    if(cnt!=1){
        AC=false;
    }
    rep(i,len-1){
        
        if(S[i+1]<'a'&&S[i+1]!='C'){
            AC=false;
            break;
        }
    }
    if(AC==true){
        cout<<"AC"<<endl;
    }
    else{
        cout<<"WA"<<endl;
    }
    
}