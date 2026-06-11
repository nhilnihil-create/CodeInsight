/*
      author  : nishi5451
      created : 14.08.2020 17:26:24
*/

#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<n; i++)
typedef long long ll;


int main(){
    int a,b;
    cin >> a >> b;
    int ans = 0;
    for(int i=a; i<=b; i++){
        if( (i%10==i/10000) && ((i%100)/10 == (i%10000)/1000))
            ans++;
    }
    cout << ans << endl;
    return 0;
}