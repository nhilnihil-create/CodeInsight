#include <bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int i=0;i<int(N);++i)
using ll = long long;
const int INF = 2147483647;
// const ll INF = 1000000000000000000LL;

int main() {
    int h,w;
    cin >> h >> w;
    char field[h][w];
    rep(i,h)
        rep(j,w)
            cin >> field[i][j];
    bool flag = true;
     rep(i,h){
        if(!flag)
            break;
        rep(j,w){
            if(field[i][j]!='#')
                continue;
            if(i!=0&&field[i-1][j]=='#')
                continue;
            if(i!=h&&field[i+1][j]=='#')
                continue;
            if(j!=0&&field[i][j-1]=='#')
                continue;
            if(j!=w&&field[i][j+1]=='#')
                continue;    
            flag = false;
        }           
     }
     if(flag) cout << "Yes" << endl;
     else cout << "No" << endl;
}

