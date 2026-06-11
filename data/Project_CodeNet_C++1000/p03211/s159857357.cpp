/*
      author  : nishi5451
      created : 14.08.2020 22:59:03
*/

#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<n; i++)
typedef long long ll;

const int INF = 2e9;

int main(){
    string s;
    cin >> s;
    int ans = INF;
    for(int i=0; i<int(s.size())-2; i++){
        string t = s.substr(i,3);
        int dif = abs(atoi(t.c_str()) -753);
        ans = min(ans,dif);
    }
    cout << ans << endl;
    return 0;
}