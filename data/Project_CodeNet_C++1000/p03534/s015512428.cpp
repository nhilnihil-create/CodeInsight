#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using db = double;
#define fi first
#define se second
#define pb push_back
#define all(v) (v).begin(),(v).end()
#define siz(v) (ll)(v).size()
#define rep(i,n) for(ll i=0;i<(ll)(n);i++)
#define repi(i,x,n) for(ll i=x;i<(ll)(n);i++)
typedef pair<int,int> P;
typedef pair<ll,ll> PL;
const ll mod = 1000000007;
const ll INF = 1000000099;
vector<ll> dx={-1,1,0,0},dy={0,0,-1,1};
//cin.tie(0);
//ios::sync_with_stdio(false);



signed main(){
    string s;cin>>s;
    vector<int> v(3,0);
    for(int i=0;i < siz(s);i++)
    {
        if(s[i]=='a')v[0]++;
        else if(s[i]=='b')v[1]++;
        else v[2]++;
    }
    sort(all(v));


    if(v[0]==0){
        if(v[2]==1 && v[1]<=1){
            cout<<"YES"<<endl;
        }else{
            cout<<"NO"<<endl;
        }
    }else{
        if(v[2]-1<=v[1] && v[2]-1 <=v[0]){
            cout<<"YES"<<endl;
        }else{
            cout<<"NO"<<endl;
        }
    }
}