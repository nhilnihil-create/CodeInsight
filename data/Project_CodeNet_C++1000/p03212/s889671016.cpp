#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD=1000000007;
#define INF 1LL<<30
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define all(x) (x).begin(),(x).end()

ll n;
vector<ll> v;

void dfs(string s){
    ll x=stoll(s);
    if(x<=n){
        bool o7=false,o5=false,o3=false;
        rep(i,s.size()){
            if(s[i]=='7') o7=true;
            else if(s[i]=='5') o5=true;
            else if(s[i]=='3') o3=true;
        }
        if(o7 && o5 && o3) v.push_back(x);
        dfs(s+'7');
        dfs(s+'5');
        dfs(s+'3');
    }
}


int main(){
    cin>>n;
    dfs("7");
    dfs("5");
    dfs("3");

    cout<<v.size()<<endl;
} 
