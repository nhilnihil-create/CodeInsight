#include<bits/stdc++.h>
using namespace std;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
 
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define rep1(i, n) for (ll i = 1; i <= (ll)(n); i++)
#define INF 10000000000
#define MOD 1000000007
using ll = long long;
using pint = pair<int,int>;
using pll = pair<ll,ll>;
using Graph = vector<vector<int>>;

int main(){
    string s,t; cin>>s>>t;
    sort(s.begin(),s.end());
    sort(t.rbegin(),t.rend());
    // cout<<s<<endl;
    // cout<<t<<endl;
    rep(i,min(s.size(),t.size())){
        if(s[i]<t[i]){
            cout<<"Yes"<<endl;
            return 0;
        }else if(s[i]==t[i])continue;
        else{
            cout<<"No"<<endl;
            return 0;
        }
    }
    if(s.size()>=t.size()){
        cout<<"No"<<endl;
        return 0;
    }
    cout<<"Yes"<<endl;
    return 0;
}
