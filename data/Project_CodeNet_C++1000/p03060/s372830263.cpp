#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

static const int MAX = 20;
int c[MAX], v[MAX];

int main(){
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> v[i];
    }
    for(int i = 0; i < n; i++){
        cin >> c[i];
    }
    int ans = 0;
    for(int i = 0; i < (1 << n); i++){
        int xy = 0;
        for(int j = 0; j < n; j++){
            if(i >> j & 1){
                xy += v[j] - c[j];
            }
        }
        ans = max(ans, xy);
    }
    cout << ans << endl;
    return 0;
}