#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    vector <int> a1(n+1,0);
    vector <int> a2(n+1,0);
    for(int i = 1; i <= n; i++){
        cin >> a1[i];
        a1[i]+=a1[i-1];
    }
    for(int i = 1; i <= n; i++){
        cin >> a2[i];
        a2[i]+=a2[i-1];
    }
    long ans = 0;
    for(int i = 1; i <= n; i++){
        ans = max((long)a1[i]+a2[n]-a2[i-1],ans);
    }
    cout << ans << endl;
    return 0;
}