#include <bits/stdc++.h>

using namespace std;
#define all(a)a.begin(),a.end()
using ll=long long;
const int INF = 1<<30;
const ll INFll =1LL<<62;
const int mod =(1e9)+7;
using P = pair<ll,ll>;

int main(){
    ll n;cin >>n;
    vector<ll>ans;
    ll i=0;
    if(n==0){
        ans.push_back(0);
    }
    while(n!=0){
        if(n%2==0){
            ans.push_back(0);
        }
        else {
            ans.push_back(1);
            if(i%2==0)n--;
            else n++;
        }
        n/=2;
        i++;
    }
    reverse(all(ans));
    for(auto u:ans){
        cout <<u;
    }
    cout<<endl;
    return 0;
}