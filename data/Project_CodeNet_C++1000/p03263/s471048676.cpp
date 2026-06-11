#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define reps(i, n, m) for (int i = (int)(n); i <= (int)(m); i++)
#define ALL(obj) (obj).begin(), (obj).end()
#define rALL(obj) (obj).rbegin(), (obj).rend()
//#define int long long

signed main(){
    int h, w;
    cin >> h >> w;
    
    vector<vector<int>> coins(h+1,vector<int>(w+1));
    rep(i,h)rep(j,w) cin >> coins[i+1][j+1];
    
    vector<int> x(h*w), y(h*w);
    rep(i,h*w){
        x[i] = i / w + 1;
        y[i] = (x[i] % 2) ? (i%w + 1) : (w - i%w);
    }
    
    queue<string> q;
    bool record = false;
    int operation = 0;
    
    rep(i,h*w-1){
        bool is_odd = coins[x[i]][y[i]] % 2 == 1;
        if(is_odd || record){
            if(is_odd && record){
                record = false;
            }else{
                string str = "";
                str += to_string(x[i]) + " ";
                str += to_string(y[i]) + " ";
                str += to_string(x[i+1]) + " ";
                str += to_string(y[i+1]);
                q.push(str);
                operation++;
                record = true;
            }
        }
    }
    
    cout << operation << endl;
    while(!q.empty()){
        cout << q.front() << endl;
        q.pop();
    }
}