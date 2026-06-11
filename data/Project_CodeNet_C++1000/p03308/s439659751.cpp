/*
      author  : nishi5451
      created : 14.08.2020 19:29:14
*/

#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<n; i++)
typedef long long ll;

const int INF = 1e9+1;

int main(){
    int n;
    cin >> n;
    int a=INF,b=0;
    rep(i,n){
        int tmp;
        cin >> tmp;
        a = min(a,tmp);
        b = max(b,tmp);
    }
    cout << abs(a-b) << endl;
    return 0;
}