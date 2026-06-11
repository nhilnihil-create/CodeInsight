#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, s, n) for (int i = (s); i < (int)(n); i++)

int main(){
    int n; cin >> n;
    int x = 1; int y = 2;
    bool ok = false;
    while(x*y <= 2*n){
        if(x*y == 2*n){
            ok = true; break;
        }
        x++; y++;
    }
    if(!ok){
        cout<<"No"<<endl;
        return 0;
    }else cout<<"Yes"<<endl;

    vector<vector<int>> sets(y);
    rep(i,0,y) sets[i].push_back(x);
    sets[0].push_back(1); sets[1].push_back(1); 
    int now = 1; int stop = 3; int step = 3; int h2 = 2;
    while(now < n){
        int h1 = 0;
        while(now < stop){
            now++;
            sets[h1++].push_back(now);
            sets[h2].push_back(now);
        }
        h2++; stop+=step++;
    }

    cout<<y<<endl;
    rep(i,0,y){
        rep(j,0,x+1){
            cout<<sets[i][j]<<" ";
        }
        cout<<endl;
    }
}