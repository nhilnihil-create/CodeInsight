#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll MOD = 1000000007;
const ld PI = acos(-1);  
const ld EPS = 0.0000000001;


int main(){
    int h, w;   cin >> h >> w;
    vector<vector<ll>> c(10, vector<ll>(10, 1e+15));
    
    for(int i=0; i<10; i++)
        for(int j=0; j<10; j++)  cin >> c.at(i).at(j);

    for(int k=0; k<10; k++)
        for(int i=0; i<10; i++)
            for(int j=0; j<10; j++)
                c[i][j] = min(c[i][j], c[i][k]+c[k][j]);
    
    ll res=0;
    
    for(int i=0; i<h; i++){
        for(int j=0; j<w; j++){
            int x;  cin >> x;
            if(x==-1) continue;
            res += c[x][1];
        }
    }
    cout << res << endl;

}

