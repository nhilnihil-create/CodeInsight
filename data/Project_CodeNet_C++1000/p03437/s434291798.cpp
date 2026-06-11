#include <bits/stdc++.h>
#include <math.h>
#define INF 10000000000
#define rep(i, n) for(int i = 0; i < (n); i++)
#define rrep(i, n) for(int i = 0; i <= (n); i++)
using namespace std;
typedef long long ll;

int main(){
    int X, Y;
    cin >> X >> Y;

    int ans = X;
    if(X%Y == 0){
        ans = -1;
    }
    cout << ans << endl;
}