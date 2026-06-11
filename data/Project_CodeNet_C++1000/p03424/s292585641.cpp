#include<bits/stdc++.h>
using namespace std;

int main(){
    string s;
    int y=0;
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>s;
        if(s=="Y")y=1;
    }
    if(y==0)cout<<"Three"<<endl;
    else{
        cout<<"Four"<<endl;
    }
    return 0;
}