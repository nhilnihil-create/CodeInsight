//#include <bits/stdc++.h>
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <string>
#include <vector>
#include <map>
#include <queue>

using namespace std;

typedef long long ll;
typedef vector<int> vint;
typedef vector<vector<int> > vvint;
typedef vector<long long> vll, vLL;
typedef vector<vector<long long> > vvll, vvLL;
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n) for(int i=0;i<n;++i)
#define mod (ll)(1e9+7)
#define FIX(a) ((a)%mod+mod)%mod
#define ALL(obj) (obj).begin(), (obj).end()
#define rALL(obj) (obj).rbegin(), (obj).rend()
#define INF 1000000000 //1e9
#define LLINF 2000000000000000000LL //2e18
#define fi first
#define se second
#define pb push_back
int dy[]={0, 0, 1, -1};
int dx[]={1, -1, 0, 0};
int hwmax = 10001;
int h,w;
vvint fi(hwmax,vint(hwmax,0));
int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> h >> w;
    queue<pair<int,int> > q1,q2;
    int cnt = 0;
    REP(i,h){
        string s;
        cin >> s;
        REP(j,w){
            if(s[j]=='#'){
                fi[i][j]=1;
                q1.push(make_pair(i,j));
                cnt++;
            }else{
                fi[i][j]=0;
            }
        }
    }
    int ans = 0;
    while(cnt<h*w){
        ans++;
        while(!q1.empty()){
            pair<int,int> p = q1.front();
            q1.pop();
            int i = p.fi;
            int j = p.se;
            if(j+1<w&&fi[i][j+1]==0){
                cnt++;
                fi[i][j+1]=1;
                q2.push(make_pair(i,j+1));
            }
            if(j-1>=0&&fi[i][j-1]==0){
                cnt++;
                fi[i][j-1]=1;
                q2.push(make_pair(i,j-1));
            }
            if(i+1<h&&fi[i+1][j]==0){
                cnt++;
                fi[i+1][j]=1;
                q2.push(make_pair(i+1,j));
            }
            if(i-1>=0&&fi[i-1][j]==0){
                cnt++;
                fi[i-1][j]=1;
                q2.push(make_pair(i-1,j));
            }
        }
        while(!q2.empty()){
            auto p = q2.front();
            q2.pop();
            q1.push(p);
        }
    }
    cout << ans << endl;

    return 0;
}