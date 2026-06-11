/*
      author  : nishi5451
      created : 14.08.2020 18:23:27
*/

#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<n; i++)
typedef long long ll;


int main(){
    int x;
    cin >> x;
    int ans = 1;
    for(int i=2; i*i<=x; i++){
        int now = i;
        while(now*i <= x){
            now*=i;
        }
        if(now != i){
            ans = max(ans,now);
        }
    }
    cout << ans << endl;
    return 0;
}