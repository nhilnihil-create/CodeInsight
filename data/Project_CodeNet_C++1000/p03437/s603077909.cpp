#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define FAST_IO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
int main(){
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ll x,y;
    while(cin>>x>>y){
        if(x%y==0)cout<<"-1"<<endl;
        else cout<<x<<endl;
    }
    return 0;
}
