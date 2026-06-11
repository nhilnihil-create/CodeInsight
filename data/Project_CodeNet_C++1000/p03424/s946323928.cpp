#include<bits/stdc++.h>
using namespace std;
using ll=long long int;
#define rep(i,n) for(int i=0;i<(n);i++)

int main(){
    int n;
    cin>>n;
    set<char>s;
    rep(i,n){
        char c;
        cin>>c;
        s.insert(c);
    }
    int cnt=s.size();
    if(cnt==3)cout<<"Three"<<endl;
    else cout<<"Four"<<endl;
}