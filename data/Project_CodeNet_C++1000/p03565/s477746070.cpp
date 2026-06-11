#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
using ll = long long;
using p = pair<int,int>;
using Graph = vector<vector<int>>;
int main(int argc, const char * argv[]) {

    cin.tie(0);
    ios::sync_with_stdio(false);

    string s,t;
    cin>>s>>t;
    int start;

    for(int i=s.size()-1;i>=0;i--){
        string u=s.substr(i,t.size());
        if(t.size()!=u.size())continue;
        bool flag=true;
        for(int j=0;j<t.size();j++){
            if(t[j]!=u[j]&&u[j]!='?'){
                flag=false;
                break;
            }
        }
        if(flag){
            for(int j=0;j<u.size();i++,j++){
                s[i]=t[j];
            }
            rep(j,s.size()){
                if(s[j]=='?')s[j]='a';
            }
            cout<<s<<endl;
            return 0;
        }
    }
    cout<<"UNRESTORABLE"<<endl;


    return 0;
}
