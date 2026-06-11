#include<bits/stdc++.h>
using namespace std;
using ll=long long int;
#define rep(i,n) for(int i=0;i<(n);i++)

int main(){
    int n,t;
    cin>>n>>t;
    vector<int>c;
    rep(i,n){
        int a,b;
        cin>>a>>b;
        
        if(b<=t){
            c.push_back(a);
        }else c.push_back(10000);

    }
    sort(c.begin(),c.end());
    if(c[0]==10000)cout<<"TLE"<<endl;
    else cout<<c[0]<<endl;

}