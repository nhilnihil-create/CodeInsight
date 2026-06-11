#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1e9+7;
int main() {
    int n;
    cin >> n;
    vector<char>s(n);
    for(int i=0;i<n;i++){
        cin >> s[i];
    }
    vector<int>e(n,0);
    vector<int>w(n,0);
    if(s[0]=='W') w[0]++;
    else e[0]++;

    for(int i=1;i<n;i++){
        if(s[i]=='W'){
            w[i] = w[i-1] + 1;
            e[i] = e[i-1];
        }
        else {
            w[i] = w[i-1];
            e[i] = e[i-1] + 1;
        }
    }
    vector<int>ans(n,0);
    for(int i=0;i<n;i++){
        if(i==0) ans[i] == e[n-i] - e[i];
        ans[i]=w[i-1]+(e[n-1]-e[i]);
    }
    sort(ans.begin(),ans.end());
    cout << ans[0] << endl;
}