#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)
using ll=long long;
using namespace std;

int main(){
    int n;
    cin>>n;
    string w;
    cin>>w;
    set<string> dict;
    dict.insert(w);
    size_t l=w.length();
    char c=w[l-1];
    bool flag=true;
    rep(i,n-1){
        string x;
        cin>>x;
        l=x.length();
        if(c!=x[0]){
            flag=false;
        }
        dict.insert(x);
        c=x[l-1];
    }
    if(n!=dict.size()) flag=false;
    if(flag) cout<<"Yes"<<"\n";
    else cout<<"No"<<"\n";
    return 0;
}