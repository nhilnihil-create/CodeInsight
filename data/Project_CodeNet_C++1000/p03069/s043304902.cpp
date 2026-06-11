#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    string s;
    cin >> n >> s;

    vector<int> white(n+1);
    for(int i=0; i<n; i++){
        if(s[i] == '.') white[i+1] = 1;
    }
    for(int i=0; i<n; i++){
        white[i+1] += white[i];
    }

    int ans = 1e6;// INF
    for(int i=0; i<=n; i++){
        int flip = (i - white[i]) + (white[n] - white[i]);
        ans = min(ans, flip);
    }
    cout << ans << endl;
    return 0;
}