#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int,int>;
#define INF 1000000001

int main() {
    int n;cin >> n;
    vector<vector<int>> v(n-1, vector<int>(3, 0));
    for(int i = 0; i < n-1; i++) {
        int c,s,f;cin >> c >> s >> f;
        v[i][0]=c;
        v[i][1]=s;
        v[i][2]=f;
    }

    for(int i = 0; i < n-1; i++) {
        ll ans=v[i][1]+v[i][0];

        for(int j = i+1; j < n-1; j++) {
            if(ans<v[j][1]) ans=v[j][1]+v[j][0];
            else{
                int x=(ans-1)/v[j][2]+1;
                ans = x*v[j][2]+v[j][0];
            }
        }
        cout << ans << endl;
    }
    cout << 0 << endl;

    return 0;
}