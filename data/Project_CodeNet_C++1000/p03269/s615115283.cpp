#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
struct edges{
    ll u,v,w;
    void print(){
        cout<<u<<" "<<v<<" "<<w<<"\n";
    }
};
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    vector<edges> a;
    ll l;cin>>l;
    ll n=20;
    for(ll i=2;i<=n-1;i++){
        a.push_back({i-1,i,0});
        a.push_back({i-1,i,(1ll<<(i-2))});
    }
    ll w=0;
    for(ll i=n-1;i>=1;i--){
        ll cur = (1ll<<(i-1));
        while(l>=cur){
            a.push_back({i,n,w});
            l-=cur;
            w+=cur;
        }
    }
    cout<<n<<" "<<a.size()<<"\n";
    for(auto &ele:a)ele.print();
}