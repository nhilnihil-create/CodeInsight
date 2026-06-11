#include <bits/stdc++.h>
#define rep(i,n) for (int i= 0;i<(n);++i)
using namespace std;
typedef long long ll;
typedef pair<int,int> P;


int main(){
    int n;cin>>n;
    vector <ll> d(n);
    rep(i,n)cin>>d.at(i);
    int m;cin>>m;
    vector<ll> t(m);
    rep(i,m)cin>>t.at(i);
    multiset<int> ans;


    rep(i,n){
        ans.insert(d[i]);
    }
    rep(i,m){
        if(ans.count(t[i])){
            ans.erase(ans.find(t[i]));
        }
        else {
            cout<<"NO"<<endl;
            return 0;
        }
    }

    cout<<"YES"<<endl;
}
