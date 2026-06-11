#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define FOR(i,a,b) for(int i=(a); i<(b); i++)
#define ALL(v) v.begin(), v.end()
#define RALL(v) v.rbegin(), v.rend()
typedef long long ll;
int main(){
    string s; cin >> s;
    int n = s.size();
    int x,y; cin >> x >> y;
    deque<int> dx,dy;
    int cnt = 0;
    int str = 0;
    rep(i,n){
        if(s[i] == 'T'){
            if(cnt % 2) dy.push_back(str);
            else dx.push_back(str);
            cnt++;
            str = 0;
        }else{
            str++;
        }
    }
    if(str){
        if(cnt % 2) dy.push_back(str);
        else dx.push_back(str);
    }
    if(dy.empty()) dy.push_back(0);
    int fx = dx.front();
    x -= fx;
    dx.pop_front();
    if(dx.empty()) dx.push_back(0);
    int nx = dx.size(); int ny = dy.size();
    sort(RALL(dx)); sort(RALL(dy));

    bool okx = false, oky = false;
    int tmpx = 0, tmpy = 0;
    rep(i,nx){
        if(tmpx > x) tmpx -= dx[i];
        else tmpx += dx[i];
    }
    if(tmpx == x) okx = true;

    rep(i,ny){
        if(tmpy > y) tmpy -= dy[i];
        else tmpy += dy[i];
    }
    if(tmpy == y) oky = true;
    if(okx && oky) cout << "Yes" << endl;
    else cout << "No" << endl;
}