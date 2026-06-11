#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
#include<queue>
#include<map>
#include<math.h>
#include<string>
#include <cctype>
#include <cstdlib>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define reps(i, s, n) for (int i = s; i < (int)(n); i++)
#define out(x) cout << x << endl
#define INF 1ll<<60;

using namespace std;
using ll = long long;
typedef pair<int, int> P;

int main(){
    int n, m, x, y;
    cin >> n >> m >> x >> y;
    int x_n[n], y_n[m];
    rep(i, n) cin >> x_n[i];
    rep(i, m) cin >> y_n[i];

    bool last_flag=false;
    for(int i=x+1; i<=y; i++){
        bool flag=true;
        rep(j, n) if(x_n[j]>=i) flag=false;
        rep(z, m) if(y_n[z]<i) flag=false;
        if(flag==true) {last_flag=true;}
    }
    if(x>y) last_flag=false;
    
    if(last_flag==true) out("No War");
    else out("War");
}