#include <bits/stdc++.h>
#include <string>
using namespace std;
typedef long long ll;

int main(){
    string s,t;
    cin>>s>>t;
    
    vector<int> ss(s.length());
    vector<int> tt(t.length());
    
    for(ll i=0;i<s.length();++i){
        ss[i]=s[i];
    }
    for(ll i=0;i<t.length();++i){
        tt[i]=t[i];
    }
    sort(ss.begin(),ss.end());
    sort(tt.begin(),tt.end(),greater<ll>());
    for(ll i=0;i<min(s.length(),t.length());++i){
        //cout<<ss[i]<<","<<tt[i]<<endl;
        if(ss[i]<tt[i]){
            cout<<"Yes";
            return 0;
        }else if(ss[i]>tt[i]){
            cout<<"No";
            return 0;
        }
    }
    if(s.length()<t.length()){
        cout<<"Yes";
    }else{
        cout<<"No";
    }
}