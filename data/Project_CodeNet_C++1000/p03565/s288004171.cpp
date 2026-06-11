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
string s,t;
int main(){
    cin >> s >> t;
    vector<string> vs;
    rep(i,s.size() -t.size()+1){
        string nows = s;
        int id = i;
        bool ok = 1;
        rep(j,t.size()){
            if(nows[id]!=t[j] && nows[id]!='?') ok = 0;
            else nows[id] = t[j];
            id++;
        }
        while(id<nows.size()){
            if(nows[id]=='?') nows[id]='a';
            id++;
        }
        rep(j,i) if(nows[j]=='?') nows[j] = 'a';
        if(ok) vs.push_back(nows);
    }
    sort(vs.begin(),vs.end());
    if(vs.size()==0) cout<<"UNRESTORABLE"<<endl;
    else cout << vs[0] << endl;
    return 0;
}