#include <bits/stdc++.h>
using namespace std;

int main(){
    int N;
    string S;
    cin>>N>>S;
    int min=300000,now=0;
    vector<int> W(N+1);
    vector<int> E(N+1);
    for(int i=0;i<N;i++){
        if(S[i]=='W'){
            W[i+1]=W[i]+1;
            E[i+1]=E[i];
        }
        if(S[i]=='E'){
            E[i+1]=E[i]+1;
            W[i+1]=W[i];
        }
    }
    for(int i=0;i<N;i++){
        now+=W[i]-W[0];
        now+=E[N]-E[i+1];
        if(now<min){
            min=now;
        }
        now=0;
        
    }
    cout<<min<<endl;

}