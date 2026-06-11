#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)
using namespace std;
using ll=long long;
using vi=vector<int>;
using vll=vector<ll>;
#define MOD 1000000007

int main(){
    int n,m;
    cin >> n >> m;
    map<int,int> mp;
    ll ans=0;
    rep(i,n){
        int a;
        cin >> a;
        mp[a]++;
    }
    rep(i,m){
        int b,c;
        cin >> b >> c;
        int b_ori=b;
        vi save;
        for(auto &x:mp){
            if(c<=x.first) break;
            int temp=x.second-b;
            if(temp<=0){
                b-=x.second;
                save.push_back(x.first);
            }else{
                b=0;
                x.second=temp;
                break;
            }
        }
        for(int x:save){
            mp.erase(x);
        }
        mp[c]+=b_ori-b;
    }
    for(auto x:mp){
        ans+=(ll)x.first*x.second;
    }
    cout << ans << endl;
}