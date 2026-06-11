#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<cstdlib>
#include<queue>

using namespace std;

#define rep(i, n) for(int i = 0; i < n; i++)

int ans = 1000000000;
int n, a, b, c;
int l[8];

void f(int* x, int m){
    
    if (m == n){
        int mp = 0;
        int s[3];
        rep(i, 3) s[i] = 0;
        rep(i, n){
            if (x[i] == 3) continue;
            if(s[x[i]] != 0) mp += 10;
            s[x[i]] += l[i];
        }
        rep(i, 3) if(s[i] == 0) return;
        mp += abs(s[0] - a) + abs(s[1] - b) + abs(s[2] - c);
        ans = min(ans, mp); 
        return;
    }

    int y[n];
    rep(i, n) y[i] = x[i];
    rep(i, 4){
        y[m] = i;
        f(y, m + 1);
    }
}

int main(){
    cin >> n >> a >> b >> c;
    rep(i, n) cin >> l[i];
    int per[n];
    
    f(per, 0);
    cout << ans << endl;
}
