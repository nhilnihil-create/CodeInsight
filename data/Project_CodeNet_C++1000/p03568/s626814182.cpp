#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
#define prtd(var, i) cout << fixed << setprecision(i) << var << endl;
#define ll long long
#define P pair<int, int>
using namespace std;

int main(){
    int n;
    cin >> n;

    int oddc = 1;
    rep(i, n){
        int cnt = 0;
        int a;
        cin >> a;
        for(int j = -1; j <= 1; j++){
            if((a+j)%2 == 1) cnt++;
        }
        oddc *= cnt;
    }
    int ans = 1;
    rep(i, n) ans *= 3;
    cout << ans - oddc << endl;
    return 0;
}   

/*

2 3
1 2 3, 2 3 4

all:3*3=9
odd:2*1=2
9-2
*/