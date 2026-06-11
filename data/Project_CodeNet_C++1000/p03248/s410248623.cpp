#include<bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL)
#define ll long long
#define ld long double
#define pii pair<int,int>
#define pll pair<ll,ll>
#define pld pair<ld,ld>
const int MAXN = 1e5+7;
vector<int> sz;
int cur_sz=1, cur_pai=2, prev_pai=1;
bool mrk[MAXN];
vector<pii> E;
string s;
int main(){
    cin >> s;
    int n = (int)s.size();
    if(s[n-1]=='1' || s[0]=='0'){cout<<"-1"<<endl; return 0;}
    for(int i=1; i<=n/2; i++){
        if(s[i-1] != s[n-i-1]){cout<<"-1"<<endl; return 0;}
        if(s[i-1]=='1')sz.push_back(i);
    }
    for(int i=1; i<(int)sz.size(); i++){
        int si = sz[i];
        int prev = sz[i-1];
        E.push_back({prev_pai, cur_pai});
        mrk[prev_pai]=true;
        int atual = prev+1;
        int prox = cur_pai+1;
        while(atual<si){
            E.push_back({cur_pai, prox});
            mrk[prox]=true;
            atual++;
            prox++;
        }
        prev_pai = cur_pai;
        cur_pai = prox;
    }
    for(int i=1; i<n; i++){
        if(mrk[i])continue;
        E.push_back({i, n});
    }
    for(int i=0; i<(int)E.size(); i++)cout<<E[i].first<<" "<<E[i].second<<endl;
}