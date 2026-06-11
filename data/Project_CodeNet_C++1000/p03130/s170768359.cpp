#include<bits/stdc++.h>
using namespace std;

int main(){
    map<int,int> path;
    for(int i=0;i<4;i++){
        path[i]=0;
    }
    for(int i=0;i<3;i++){
        int a,b;cin>>a>>b;a--;b--;
        path[a]++;
        path[b]++;
    }
    for(int i=0;i<4;i++){
        if(path[i]==3){
            cout<<"NO"<<endl;
            return 0;
        }
    }
    cout<<"YES"<<endl;
    return 0;
}