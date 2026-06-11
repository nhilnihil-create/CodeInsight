#include<bits/stdc++.h>
using namespace std;

int main(void){
    int n, oldt = 0, oldx = 0, oldy = 0;
    int t[100001], x[100001], y[100001];
    bool can = true;
    string ans;
    cin >> n;
    for(int i = 0; i < n; i++) cin >> t[i] >> x[i] >> y[i];
    for(int i = 0; i < n; i++){
        int dt = t[i] - oldt;
        int dist = abs(x[i] - oldx) + abs(y[i] - oldy);
        if(dist > dt){
            can = false;
            break;
        }
        if(dist % 2 == dt % 2){
            oldt = t[i]; oldx = x[i]; oldy = y[i];
        } else {
            can = false;
            break;
        }
    }
    if(can) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}