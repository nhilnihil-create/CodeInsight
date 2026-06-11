#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<cmath>
#include<bitset>
#include<deque>
#include<functional>
#include<iterator>
#include<map>
#include<set>
#include<stack>
#include<queue>
#include<utility>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
#define a first
#define b second
#define sz(x) (ll)((x).size())
#define pb push_back
#define mp make_pair
#define bg begin()
#define ed end()
#define all(x) (x).bg,(x).ed
#define rep(i,n) for(ll i=0;i<(n);i++)
#define rep1(i,n) for(ll i=1;i<=(n);i++)
#define rrep(i,n) for(ll i=(n)-1;i>=0;i--)
#define rrep1(i,n) for(ll i=(n);i>=1;i--)
#define FOR(i,a,b) for(ll i=(a);i<(b);i++)
const ll MOD=1000000007;
const ll INF=1000000000000000;
template<class T> inline bool chmin(T& a, T b){if(a>b){a=b;return true;}return false;}
template<class T> inline bool chmax(T& a, T b){if(a<b){a=b;return true;}return false;}
vector<ll> pw2(62,1);vector<ll> pw10(19,1);

int main(){
    {rep1(i,61) pw2[i]=2*pw2[i-1];}
    {rep1(i,18) pw10[i]=10*pw10[i-1];}
    
    string s,t; cin>>s>>t;
    priority_queue<string,vector<string>,greater<string> > que;
    if(sz(t)>sz(s)) cout<<"UNRESTORABLE"<<endl;
    else{
        //i:tの先頭。
        rep(i,sz(s)-sz(t)+1){
            bool check=true;
            rep(j,sz(t)){
                if(s[i+j]==t[j] || s[i+j]=='?'){
                    
                }
                else{
                    check=false;
                }
            }
            
            //[i,i+sz(t))一致
            if(check){
                string tmp="";
                rep(k,sz(s)){
                    if(i<=k && k<i+sz(t)) tmp+=t[k-i];
                    else if(s[k]=='?') tmp+="a";
                    else tmp+=s[k];
                }
                que.push(tmp);
            }
        }
        if(que.empty()) cout<<"UNRESTORABLE"<<endl;
        else{
            cout<<que.top()<<endl;
        }
    }
}

