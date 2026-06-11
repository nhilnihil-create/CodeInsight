#include<bits/stdc++.h>
using namespace std;
using ll=long long int;
#define rep(i,n) for(int i=0;i<(n);i++)

int main(){
    int n;
    cin>>n;
    vector<string>w(n);
    set<string>s;
    rep(i,n){
        cin>>w[i];
        s.insert(w[i]);
    }
    rep(i,n-1){
        for(int j=n-1;j>i;j--){
           if(w[i]==w[j]){
               cout<<"No"<<endl;
               return 0;
           }
        }
    }
        
    bool ok=true;
    for(int i=1;i<n;i++){
        if(w[i-1][w[i-1].size()-1]==w[i][0])continue;
        else{
            ok=false;
            break;
        }
    }
    if(ok) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;

}