#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0;i < (n);i++)
using namespace std;
using ll = long long;
using pii = pair<int,int>;

const int INF = 2e9;



int main(){
    int n; cin >> n;
    vector<int> t(n+1), x(n+1), y(n+1);
    for(int i = 0; i < n; i++){
        cin >> t[i+1] >> x[i+1] >> y[i+1];
    }

    bool can = true;
    for(int i = 0; i < n; i++){
        int dt = t[i+1] - t[i];
        int dist = abs(x[i+1] - x[i]) + abs(y[i+1] - y[i]);
        
        if(dt < dist){
            can = false;
        }

        if(dist % 2 != dt % 2){
            can = false;
        }
    }

    cout << (can ? "Yes" : "No") << endl;
}