#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<(n); i++)
using namespace std;
using P = pair<int,int>;
using ll = long long; 

int main(){
    ll s;
    cin>>s;
    set<ll> list;
    list.insert(s);
    ll size=list.size();
    rep(i,1000000){
        if(s%2==0)s=s/2;
        else s=3*s+1;

        list.insert(s);
        if(size==list.size()){
            cout<<i+2<<endl;
            return 0;
        }else{
            size=list.size();
        }
    }
}

