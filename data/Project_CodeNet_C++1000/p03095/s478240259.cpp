//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define pp pair<int,int>
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
#define ld long double
#define al(a) (a).begin(),(a).end()
#define mk make_pair
#define check cout<<"?"<<endl;

ll MOD=1000000007;
ll mod=998244353;
int inf=1000001000;
ll INF=1e18+5;

int main(){
    ll n,ans=1;
    string s;
    cin>>n>>s;
    map<char,ll> m;
    for(auto ch : s){
        if(m.count(ch)) m[ch]++;
        else m[ch]=1;
    }
    for(auto q : m){
        ans=(ans*(q.second+1))%MOD;
    }
    ans--;
    cout<<(MOD+ans)%MOD<<endl;
}