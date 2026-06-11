#include <bits/stdc++.h>
using namespace std;

int main(void){
    string S,T;cin>>S>>T;
    for(int i=0;i<S.size();i++){
        char tmp=S[S.size()-1];
        for(int l=0;l<S.size()-1;l++){
            S[S.size()-l-1]=S[S.size()-l-2];
        }
        S[0]=tmp;
        if(S==T){
            cout<<"Yes"<<endl;
            return 0;
        }
    }
    cout<<"No"<<endl;
    return 0;
}