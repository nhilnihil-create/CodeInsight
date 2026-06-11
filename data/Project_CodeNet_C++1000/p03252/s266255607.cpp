#include <bits/stdc++.h>
using namespace std;
template <typename T> bool chmax(T &u, const T z) { if (u < z) {u = z; return true;} else return false; }
template <typename T> bool chmin(T &u, const T z) { if (u > z) {u = z; return true;} else return false; }
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ll long long 
//typedef pair<ll, ll> P;
const ll INF=1LL<<60;
ll gcd(ll x,ll y){return y? gcd(y,x%y) :x;}

int main(){
    string s,t;
    cin>>s>>t;
    vector<int>start(26,-1);
    vector<int>goal(26,-1);
    rep(i,s.size()){
        int a=s[i]-'a';
        int b=t[i]-'a';
        if(start[a]!=-1||goal[b]!=-1){
            if(start[a]!=b||goal[b]!=a){
                cout<<"No"<<endl;
                return 0;
            }
        }else{
            start[a]=b;
            goal[b]=a;
        }
    }
    cout<<"Yes"<<endl;
    return 0;
}