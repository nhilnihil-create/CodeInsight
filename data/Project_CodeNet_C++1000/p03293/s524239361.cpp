#include <bits/stdc++.h>
using namespace std;

int main(){
    string S,T;
    cin >>S>>T;
    
    for(int j=0;j<S.size();j++){
     string A=S;
    for(int i=0;i<S.size();i++){
    if(i==S.size()-1){
       S.at(0)=A.at(S.size()-1);
       break;
    }
     S.at(i+1)=A.at(i);
    }
    if(S==T){
        cout <<"Yes"<<endl;
        return 0;
    }
    }
    cout <<"No"<<endl;

}