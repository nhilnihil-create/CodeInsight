#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;
#define REP(i,m,n) for(int i=(m);i<(n);i++)
#define rep(i,n) REP(i,0,n)
#define pb push_back
#define mp make_pair
#define all(c) (c).begin(),(c).end()
#define rall(c) (c).rbegin(),(c).rend()
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
const ll inf=1e9+7;
const ll mod=998244353;
int main(){
    string s;
    cin>>s;
    ll n=s.size();
    rep(i,n/2+1){
        if(s[i]!=s[n-2-i]){
            cout<<-1<<endl;
            return 0;
        }
    }
    if(s[0]=='0'||s[n-1]=='1'){
        cout<<-1<<endl;
        return 0;
    }
    ll now=2;
    ll nowroot=1;
    rep(i,n-1){
        cout<<now<<' '<<nowroot<<endl;
        if(s[i]=='1')nowroot=now;
        now++;
    }
}