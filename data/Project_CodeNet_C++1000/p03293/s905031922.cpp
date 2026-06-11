#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG
#define rep(i,n) for(int i = 0; i < (n); ++i)
#define ll long long
#define P pair<ll,ll>
#define all(v) (v).begin(),(v).end()

const ll mod = 1e9+7;
const ll INF = 1e18;
const double pi = acos(-1.0);

int main(void)
{
    string s,t; cin>>s>>t;
    bool can=false;
    rep(i,s.size()){
        if(s==t){
            can=true;
            break;
        }
        s = s.back()+s.substr(0,s.size()-1);
    }
    cout<<(can?"Yes":"No")<<endl;
    return 0;
}