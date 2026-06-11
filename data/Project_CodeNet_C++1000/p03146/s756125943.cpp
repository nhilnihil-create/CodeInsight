#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
#define sz(x) int(x.size())
#define pb push_back
#define eb emplace_back
using ll=long long;
using P = pair<int,int>;
using LP=pair<ll,int>;
#define chmax(x,y) x = max(x,y)
#define chmin(x,y) x = min(x,y)
const ll MOD=1000000007,MOD2=998244353;



int main() {
    int s;
    cin>>s;
    int cnt=1;
    map<int,int> mp;
    while(1){
        if(mp.count(s)){
            cout<<cnt<<endl;
            return 0;
        }
        mp[s]=cnt;
        cnt++;
        if(s%2==0)s/=2;
        else s=3*s+1;
    }
}