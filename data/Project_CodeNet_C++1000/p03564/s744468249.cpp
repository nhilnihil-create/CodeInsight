/*
      author  : nishi5451
      created : 14.08.2020 15:44:28
*/

#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<n; i++)
typedef long long ll;


int main(){
    int n,k;
    cin >> n >> k;
    int now = 1;
    while(n--){
        if(now >= k){
            now+=k;
        }
        else now*=2;
    }
    cout << now << endl;
    return 0;
}