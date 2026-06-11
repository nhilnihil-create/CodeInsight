#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
using namespace std;
typedef long long ll;
const int inf = 1001001001;
vector<int> dx = {1,0,-1,0};
vector<int> dy = {0,1, 0,-1};

int main(){
    int h, w; cin >> h >> w;
    vector<string> g(h);
    rep(i,h) cin >> g.at(i);
    
    rep(i,h){
        rep(j,w) {
            if(g.at(i).at(j) == '#'){
                bool flag2 = 0;
            rep(k,4){
                int ny = i + dy.at(k);
                int nx = j + dx.at(k);
                if(ny > h -1 || ny < 0 || nx > w -1 || nx < 0) continue;
                if(g.at(ny).at(nx) == '#') flag2 = 1;
                }
                if(!flag2) {cout << "No" << endl; return 0;}
            }
        }
    }
    cout << "Yes" << endl;
    return 0;
}