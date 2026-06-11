#include <algorithm>
#include <iostream>
#include <vector>
#include <map>
#include <cstdio>
#include <string>
#include <cmath>
#include <queue>
#include <tuple>
#include <bitset>
#include <cassert>
#include <chrono>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <random>
#include <set>
#include <stack>
#include <time.h>

//#include <bits/stdc++.h>
#define maxs(x,y) x = max(x,y)
#define mins(x,y) x = min(x,y)
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
#define repr(i, n) for (int i = (n) - 1; i >= 0; i--)
#define FOR(i,i0,n) for(int (i)=(i0);(i)<(n);(i)++)
#define FORR(i,i0,n) for(int (i)=(n)-1; (i)>=(i0);(i)--)
#define SORT(x) sort(x.begin(),x.end())
#define SORTR(x) sort(x.begin(),x.end(),greater<int>())
#define rn return
#define fi first
#define se second
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define mt make_tuple

using namespace std;
using ll = long long;
typedef std::pair<int,int> pii;
typedef std::pair<int,double> pid;
typedef std::vector<int> vi;
typedef std::vector<pii> vii;

#define PI 3.14159265358979323846264338327950L
const int mod = 1000000007;


void solve(){
    int h,w;
    cin >> h >> w;
    vector<string> f(h);
    rep(i,h) cin >> f[i];
    
    queue<pii> q;
    int v[1000][1000] = {};
    for(int i = 0; i < h; i++){
        for(int j  = 0; j < w; j++){
            if (f[i][j] == '#'){
                q.push({i,j});
                v[i][j] = 1;
            }   
        }
    }
    
    int dx[4] = {0,0,-1,1};
    int dy[4] = {1,-1,0,0};
    int cnt = 0;
    while(q.size()){
        int sz = q.size();
        bool need = false;
        for(int i = 0; i < sz; i++){
            auto now = q.front();
            q.pop();
            for(int j = 0; j < 4;j++){
                int nx = now.first + dx[j];
                int ny = now.second + dy[j];
                if (nx >= 0 && ny >= 0 && nx < h && ny < w && v[nx][ny] == 0){
                    q.push({nx,ny});
                    v[nx][ny] = 1;
                    need = true;
                }
            }
        }
        if (need) cnt++;
    }
    cout << cnt;
}





int main(){
    int T;
    T = 1;
    // cin >> T;
    while(T--){
        solve();
        cout << endl;
    }
}



































