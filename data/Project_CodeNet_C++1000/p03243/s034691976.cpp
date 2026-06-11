#include <bits/stdc++.h>
#define rep(i,s,n) for(int i=s;i<n;i++)
#define pb push_back
#define all(x) (x).begin(),(x).end()
#define int long long
using namespace std;
using P=pair<int,int>;
using Graph=vector<vector<int>>;
using ll=long long;


ll gcd(ll A, ll B){
    if(B == 0)return A;
    return gcd(B, A % B);
}
ll lcm(ll A, ll B){
    return A * B / gcd(A, B);
}
bool root(string s){
    int n=s.length();
    if(n==2){
        if(s[0]==s[1]){
            return true;
        }
        else return false;
    }
    if(n==3){
        if(s[0]==s[2]){
            return true;
        }
        else return false;
    }
 
    return false;
}
 
 
//深さ優先
vector<int> seen;
vector<ll> h;
 
//普通の深さ優先探索seenを返す感じ
void dfs(const Graph &G,int v){
    seen[v] = 0; //v探索済み
 
    P good=make_pair(v,h[v]);
    for(auto next_v :G[v]){
        if(seen[next_v]!=-1) continue;//もう探索していた
        if(h[next_v]>good.second){
            good=make_pair(next_v,h[next_v]);
        }
        dfs(G,next_v);
    }
 
    if(!(h[v]==good.second && v==good.first)){
        seen[good.first]=1;
    }
}
 
signed main(){
    int n; cin>>n;
    for(int i=1;i<=9;i++){
        int abc=100*i+10*i+1*i;
        if(n<=abc){
            cout<<abc<<endl;
            return 0;
        }
    }
}   