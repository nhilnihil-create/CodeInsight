#include<iostream>
#include<math.h>
using namespace std;
void solve();
int main (){ 
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int t;
    //cin >> t;
    t = 1;
    for (int i = 0; i < t; i++) solve();
    
}
void solve() {
    int x,y;
    cin >> x >> y;
    long long prod = x;
    int found = 0; 
    if (x % y == 0) {
        cout << -1;
        return;
    }
    while (prod < pow(10,18) && !found) {
        if ((prod % y))found = 1;
        else{
            prod += x;
        }
    }
    if (found)cout << prod;
}