#include<iostream>
#include<algorithm>
#include<string>
#include<cmath>
#include<vector>
#include<map>
using namespace std;
/*
time:
wa:
反省:
考察:
*/
int main() {
    int n; 
    cin >> n;
    vector <int> v(n);
    vector <int> c(n);
    vector <int> cospa(n);
    int ans = 0;
    for(int i = 0; i < n; i++) {
        cin >> v[i];
    }
    for(int i = 0; i < n; i++){
        cin >> c[i];
    }
    for(int i = 0; i < n; i++){
        if((v[i]-c[i]) <= 0) continue;
        ans += (v[i]-c[i]);
    }
    cout << ans << endl;
    return 0;
}