#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

int main(){
    int n;
    cin>>n;
    bool flag=false;
    for(int i=0;i<n;i++){
        char c;
        cin>>c;
        if(c=='Y')flag=true;
    }
    if(flag)cout<<"Four"<<endl;
    else cout<<"Three"<<endl;
    return 0;
}