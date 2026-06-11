#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)
using namespace std;
using ll = long long;
int main(void){
    int N;
    cin>>N;
    string FW,W;
    map<string,int> check;
    cin>>FW;
    bool judge=true;
    int len=FW.size()-1;
    
    char lw=FW[len];
    check[FW]++;
    rep(i,N-1){
        cin>>W;
        len=W.size()-1;
        if(lw!=W[0]){
            judge=false;
            break;
        }
        lw=W[len];
        check[W]++;
        if(check[W]==2){
            judge=false;
            break;
        }
    }
    if(judge==true){
        cout<<"Yes"<<endl;
    }
    else{
        cout<<"No"<<endl;
    }
   
}