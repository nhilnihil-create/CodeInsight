#include<bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i,n) for(int i=0;i< (n);i++)
#define rep1(i,n) for(int i=1;i<= (n);i++)
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;

const static ll MOD = (1e+9)+7;

ll modpow(ll a,ll n){
    if(n==0)return 1;
    if(n%2==1)return a*modpow(a,n-1)%MOD;
    ll t = modpow(a,n/2) % MOD;
    return t*t % MOD;
}

int main(){
    string s;cin>>s;
    vector<char> s_,s__;
    rep(i,s.size()){
        if(s[i] == 'x')continue;
        s_.push_back(s[i]);
        s__.push_back(s[i]);
    }
    reverse(s__.begin(),s__.end());
    for(int i = 0;i < s_.size();i++){
        if(s_[i]!=s__[i]){
            cout<<-1<<endl;
            return 0;
        }
    }
    int i = 0,j = 0;
    vector<int> lst(s_.size()+1,0);

    while(j < s_.size()){
        if(s[i] == s_[j]){
            i++;j++;
        }else{
            lst[j]++;
            i++;
        }
    }
    if(i < s.size())lst[s_.size()]=s.size()-i;
    auto it_b = lst.begin();
    auto it_e = lst.end()-1;
    ll ans = 0;
    while(it_b < it_e){
        ans += abs(*it_b - *it_e);
        it_b++;it_e--;
    }
    cout<<ans<<endl;
    return 0;
}