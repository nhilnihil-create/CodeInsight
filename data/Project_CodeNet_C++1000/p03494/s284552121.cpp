/*
      author  : nishi5451
      created : 14.08.2020 16:07:08
*/

#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<n; i++)
typedef long long ll;

int INF = 1001001001;

int main(){
    int n;
    cin >> n;
    int ans = INF;
    for(int i=0; i<n; i++){
        ll a;
        cin >> a;
        int now = 0;
        while(a%2==0){
            a/=2;
            now++;
        }   
        ans = min(ans,now); 
    }
    cout << ans << endl;
    return 0;
}