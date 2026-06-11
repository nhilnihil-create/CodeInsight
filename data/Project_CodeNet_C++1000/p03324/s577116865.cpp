/*
      author  : nishi5451
      created : 14.08.2020 19:16:52
*/

#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<n; i++)
typedef long long ll;


int main(){
    int d,n;
    cin >> d >> n;
    if(n==100){
        int ans = 101;
        while(d--) ans*=100;
        cout << ans << endl;
    }
    else {
        int ans = n;
        while(d--) ans*=100;
        cout << ans << endl;
    }
    return 0;
}