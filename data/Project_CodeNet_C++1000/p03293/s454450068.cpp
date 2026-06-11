#include<iostream>
#include<string>
using namespace std;
int main(){
    string S,T,S1;
    int i,j,k,t=0;
    cin>>S>>T;
    S1=S;
    for(i=0;i<S.size();i++){
    for(j=0;j<S.size()-1;j++){
        S1[j+1]=S[j];
    }
    S1[0]=S[S.size()-1];
    S=S1;
    if(S==T){
        cout<<"Yes";
        t=1;
        break;
    }
    }

    if(i==S.size()){
        cout<<"No";
    }
    return 0;
}