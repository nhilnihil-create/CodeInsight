#include <bits/stdc++.h>
using namespace std;

int main(){
    int N,M;cin>>N>>M;
    vector<pair<int,int>> war(M);
    for(int i=0;i<M;i++){
        int a,b;cin>>a>>b;
        war.at(i).first=b;
        war.at(i).second=a;
    }
    sort(war.begin(),war.end());

    int res=0;
    int x=0;
    
    for(int i=0;i<M;i++){
        if(x<=war.at(i).second){
            res++;
            x=war.at(i).first;
        }
    }
    cout<<res<<endl;
}