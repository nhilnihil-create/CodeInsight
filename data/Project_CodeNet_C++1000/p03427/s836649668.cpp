#include<iostream>
using namespace std;

int main(){
    string n; cin>>n;
    int a=n[0]-'0';

    int cnt=0;
    for(int i=1;i<n.length();i++){
        if(n[i]=='9') cnt++;
    }
    if(cnt==n.length()-1) cout<<a+9*(n.length()-1)<<endl;
    else cout<<a-1+9*(n.length()-1)<<endl;
}