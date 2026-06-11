#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = int(a); i < int(b); i++)
#define rer(i, a, b) for(int i = int(a) - 1; i >= int(b); i--)
#define sz(v) (int)(v).size()
#define pb push_back
#define sc second
#define fr first
#define sor(v) sort(v.begin(),v.end())
#define rev(s) reverse(s.begin(),s.end())
#define lb(vec,a) lower_bound(vec.begin(),vec.end(),a)
#define ub(vec,a) upper_bound(vec.begin(),vec.end(),a)
#define uniq(vec) vec.erase(unique(vec.begin(),vec.end()),vec.end())
using namespace std;
typedef long long int ll;
typedef pair <ll, ll> P;

const ll MOD=1000000007;
vector<pair<P, ll>> v1, v2;
ll N;
bool used[100000];
ll res=0;
ll p=0;
ll l=0,r=0;
void f1(ll &x){
    while(used[v1[x].sc]){
        x++;
    }
    if(p<v1[x].fr.fr){
        res+=v1[x].fr.fr-p;
        p=v1[x].fr.fr;
    }
    used[v1[x].sc]=1;
    x++;
}
void f2(ll &x){
    while(used[v2[x].sc]){
        x++;
    }
    if(p>v2[x].fr.fr){
        res+=p-v2[x].fr.fr;
        p=v2[x].fr.fr;
    }
    used[v2[x].sc]=1;
    x++;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>N;
    rep(i,0,N){
        ll L,R;
        cin>>L>>R;
        v1.pb(make_pair(P(L,R), i));
        v2.pb(make_pair(P(R,L), i));
    }
    sor(v1);
    rev(v1);
    sor(v2);
    rep(i,0,N){
        if(i%2){
            f2(l);
        }
        else{
            f1(r);
        }
    }
    res+=abs(p);
    ll ans=res;
    res=0;
    p=0;
    l=0;
    r=0;
    rep(i,0,N) used[i]=0;
    rep(i,0,N){
        if(i%2==0){
            f2(l);
        }
        else{
            f1(r);
        }
    }
    res+=abs(p);
    cout <<max(ans,res)<<"\n";
}