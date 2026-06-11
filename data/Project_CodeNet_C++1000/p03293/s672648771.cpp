#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<iomanip>
using namespace std;

int main(){
    string s,t;
    cin>>s>>t;
    int len=s.size();
    bool flag=false;
    for(int i=0;i<len;i++){
        int cnt=0;
        for(int j=0;j<len;j++){
            if(t[j]==s[(j+i)%len])cnt++;
        }
        if(cnt==len)flag=true;
    }
    if(flag)cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
    return 0;
}