#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> p(n);
    for(int i = 0; i<n; i++) cin >> p[i];
    sort(p.begin(), p.end());
    reverse(p.begin(), p.end());
    int ans = 0;
    for(int i =0; i< n; i++){
        if(i == 0) p[i] /= 2;
        ans += p[i];
    }

    cout << ans << endl;
}