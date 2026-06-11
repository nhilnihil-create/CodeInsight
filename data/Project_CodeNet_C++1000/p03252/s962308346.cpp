#include<bits/stdc++.h>
#define rep(i,N) for(int i=0;i<(N);i++)
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
using namespace std;
const long long MOD = 1e9 + 7;
const long long INF = 1e12;
const int inf = 1e9;
const int mod = 1e9+7;
typedef long long ll;
typedef pair<ll,int> P;
typedef set<int> S;
int main(){
    string s,t;
    cin>>s>>t;
    map<char,int> ms,mt;
    rep(i,s.size()){
        ms[s[i]]++;
        mt[t[i]]++;
    }
    vector<int> vs,vt;
    rep(i,s.size()){
        vs.push_back(ms[s[i]]);
        vt.push_back(mt[t[i]]);
    }
    rep(i,s.size()){
        if(vs[i]!=vt[i]){
            cout<<"No"<<endl;
            return 0;
        }
    }
    cout<<"Yes"<<endl;
    return 0;
}