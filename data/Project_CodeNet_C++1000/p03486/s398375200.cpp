#include<bits/stdc++.h>
using namespace std;
using ll=long long int;
#define rep(i,n) for(int i=0;i<(n);i++)

int main(){
    string s,t;
    cin>>s>>t;
    if(s==t){
        cout<<"No"<<endl;
        return 0;
    }
    sort(s.begin(),s.end());
    sort(t.begin(),t.end());
    reverse(t.begin(),t.end());
    vector<string>u(2);
    u[0]=s;
    u[1]=t;
    sort(u.begin(),u.end());
    if(u[0]==s)cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
}