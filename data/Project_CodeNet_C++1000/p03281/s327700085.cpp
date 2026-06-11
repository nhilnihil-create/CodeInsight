/*
      author  : nishi5451
      created : 14.08.2020 19:55:30
*/

#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<n; i++)
typedef long long ll;


int main(){
    int n;
    cin >> n;
    int ans = 0;
    for(int i=1; i<=n; i+=2){
        int now = 0;
        for(int j=1; j<=i; j++){
            if(i%j==0) now++;
        }
        if(now == 8) ans++;
    }
    cout << ans << endl;
    return 0;
}