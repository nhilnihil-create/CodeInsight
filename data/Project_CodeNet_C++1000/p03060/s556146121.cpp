#include "bits/stdc++.h"
using namespace std;

int main(){
    int n, c, ans=0;
    cin >> n;
    vector<int> v(n);
    for(int i = 0; i < n; i++) cin >> v.at(i);
    for(int i = 0; i < n; i++){
        cin >> c;
        if(v.at(i)>c) ans += v.at(i)-c;
    }
    cout << ans << endl;
    return 0;
}