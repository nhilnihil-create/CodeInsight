#include<bits/stdc++.h>
using namespace std;
using lli = long long;
#define rep(i,n) for(int i=0;i<n;i++)
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

lli h, w;
vector<vector<lli>> a;

int main(void){
    cin >> h >> w;
    a.resize(h);
    rep(i, h){
        a[i].resize(w);
        rep(j, w){
            cin >> a[i][j];
        }
    }
    vector<lli> d, e, f, g;
    lli x, y;
    rep(i, h){
        if(i%2 == 0){
            for(int j = 0; j < w-1; j++){
                if(a[i][j]%2 == 0) continue;
                a[i][j]--;
                a[i][j+1]++;
                x = i+1;
                y = j+1;
                d.push_back(x);
                e.push_back(y);
                f.push_back(x);
                g.push_back(y+1);
            }
            if(i < h-1 && a[i][w-1]%2 == 1){
                a[i][w-1]--;
                a[i+1][w-1]++;
                x = i+1;
                y = w;
                d.push_back(x);
                e.push_back(y);
                f.push_back(x+1);
                g.push_back(y);
            }
        }else{
            for(int j = w-1; j >= 1; j--){
                if(a[i][j]%2 == 0) continue;
                a[i][j]--;
                a[i][j-1]++;
                x = i+1;
                y = j+1;
                d.push_back(x);
                e.push_back(y);
                f.push_back(x);
                g.push_back(y-1);
            }
            if(i < h-1 && a[i][0]%2 == 1){
                a[i][0]--;
                a[i+1][0]++;
                x = i+1;
                y = 1;
                d.push_back(x);
                e.push_back(y);
                f.push_back(x+1);
                g.push_back(y);
            }
        }
    }
    cout << d.size() << endl;
    rep(i, d.size()){
        cout << d[i] << " " << e[i] << " " << f[i] << " " << g[i] << endl;
    }
    return 0;
}
