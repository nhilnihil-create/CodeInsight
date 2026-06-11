#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,t;
    cin >> n >> t;
    int c,a;
    int ans=1e9;
    for(int i=0;i<n;i++){
        cin >> c >> a;
        if(a<=t && ans>c)ans=c;
    }
    if(ans<1e9)cout << ans << endl;
    else cout << "TLE" << endl;
}