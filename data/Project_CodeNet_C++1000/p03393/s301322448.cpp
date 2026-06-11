#define TEMPLATE_USED
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef pair<ll,ll> pl;
typedef vector<pl> vp;
const ll INF=1001001001;
const ll LINF=1001001001001001001;
const ll D4[]={0,1,0,-1,0};
const ll D8[]={0,1,1,0,-1,-1,1,-1,0};
#define _overload3(_1,_2,_3,name,...) name
#define _rep2(i,n) for(ll i=0;i<(n);++i)
#define _rep3(i,a,b) for(ll i=(a);i<(b);++i)
#define rep(...) _overload3(__VA_ARGS__,_rep3,_rep2)(__VA_ARGS__)
#define _repe2(i,n) for(ll i=0;i<=(n);++i)
#define _repe3(i,a,b) for(ll i=(a);i<=(b);++i)
#define repe(...) _overload3(__VA_ARGS__,_repe3,_repe2)(__VA_ARGS__)
#define _rrep2(i,n) for(ll i=(n)-1;i>=0;i--)
#define _rrep3(i,a,b) for(ll i=(b)-1;i>=(a);i--)
#define rrep(...) _overload3(__VA_ARGS__,_rrep3,_rrep2)(__VA_ARGS__)
#define all(x) (x).begin(),(x).end()
template<class T>
bool chmax(T &a,const T &b){if(a<b){a=b;return 1;}return 0;}
template<class T>
bool chmin(T &a,const T &b){if(b<a){a=b;return 1;}return 0;}
template<class T>
using pq=priority_queue<T,vector<T>,greater<T>>;

void solve();

int main(){
    cin.tie(0);
    ios::sync_with_stdio(0);
    solve();
}

void solve(){
    string s;cin>>s;
    ll n=s.size();

    if(n<26){
        char c='a';
        while(1){
            bool ok=true;
            rep(i,n){
                if(s[i]==c)ok=false;
            }
            if(ok){
                s+=c;
                cout<<s<<endl;
                return;
            }
            ++c;
        }
    }

    vector<char> a;
    rrep(i,n-1){
        a.push_back(s[i+1]);
        if(s[i]<s[i+1]){
            a.push_back(s[i]);
            sort(all(a));
            char nxt='z';
            for(char c1:a){
                if(c1>s[i]){
                    chmin(nxt,c1);
                    break;
                }
            }
            s[i]=nxt;
            cout<<s.substr(0,i+1)<<endl;
            return;
        }
    }
    cout<<-1<<endl;
}