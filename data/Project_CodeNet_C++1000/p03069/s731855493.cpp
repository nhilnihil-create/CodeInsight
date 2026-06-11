#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1e9+7;
const long long INF = 1e15;

int main(){
    int n;
    string s;
    cin >> n >> s;
    vector<int> w(n,0),b(n,0);
    int now = 0;
    for(int i = 0; i < n; i++){
        if(s[i] == '#') now++;
        b[i] = now;
    }
    now = 0;
    for(int i = n-1; i >= 0; i--){
        if(s[i] == '.') now++;
        w[i] = now;
    }
    int ans = mod;
    for(int i = 0; i < n; i++){
        //cout << w[i]+b[i] << endl;
        ans = min(ans,w[i]+b[i]);
    }
    cout << ans-1 << endl;

    return 0;
}