#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,s,e) for(int i=s;i<e;i++)
#define endl '\n'
int main(){
    string s,t;
    cin>>s>>t;
    bool flag=false;
    for(int i=0;i<s.size();i++){
        if(s==t)flag=true;
        s=s.back()+s.substr(0,s.size()-1);
    }
    if(flag){
        cout<<"Yes"<<endl;
    }else{
        cout<<"No"<<endl;
    }
}