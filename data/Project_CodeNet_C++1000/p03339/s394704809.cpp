#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
using P = pair<int,int>;
/* ちゃんと考えてわかって実装 */

int main(void){
    int n; string s;
    cin >> n >> s;
    int rui_W[n+1], rui_E[n+1];
    rui_W[0] = 0;
    rui_E[0] = 0;
    for(int i=0; i<n; i++){
        if(s[i] == 'E'){
            rui_E[i+1] = rui_E[i] + 1;
            rui_W[i+1] = rui_W[i];
        }
        else if(s[i] == 'W'){
            rui_E[i+1] = rui_E[i];
            rui_W[i+1] = rui_W[i] + 1;
        }
    }

    int ans = 300300;
    for(int i=0; i<n; i++){
        int left = rui_W[i];
        int right = rui_E[n] - rui_E[i+1];
        ans = min(ans, left+right);
    }
    cout << ans << endl;
    return 0;
}