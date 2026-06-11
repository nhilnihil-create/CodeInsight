#include<iostream>
using namespace std;

int main(){
    string s;
    cin>>s;
    int cnt=0;
    for(int i=0;i<(int)s.length();i++){
        if(s[i]=='0') cnt++;
    }
    cnt=min(cnt,(int)s.length()-cnt);
    cout<<cnt*2<<endl;
}