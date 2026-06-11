#include <bits/stdc++.h>
 
using namespace std;
#define repr(i,a,b) for (int i=a; i<b; i++)
#define rep(i,n) for (int i=0; i< (int) n; i++)
 
 
int main () {
    int N,X;

    cin >> N >> X;

    int min = 1000;
    rep(i,N){
        int m;
        cin >> m;
        X -= m;
        if(min > m){
            min =m;
        }
    }

    int ans = N;
    ans += X/min;

    cout << ans << endl;


}
