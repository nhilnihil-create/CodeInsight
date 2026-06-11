#include <bits/stdc++.h>
using namespace std;

bool best[25];

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    if(n == 1){
        int d;
        cin >> d;
        cout << d << endl;
        return 0;
    }
    map<int, int> D;
    D[0]++;
    for(int i = 1; i <= n; i++){
        int d;
        cin >> d;
        D[d]++;
    }
    bool left = true;
    for(auto p : D){
        if(p.second > 2 || (p.first%12 == 0 && p.second == 2)){
            cout << 0 << endl;
            return 0;
        }
        if(p.second == 2){
            best[p.first] = true;
            best[24-p.first] = true;
        }
        else{
            if(left){
                best[p.first] = true;
                left = false;
            }
            else{
                best[24-p.first] = true;
                left = true;
            }
        }
    }
    best[24] = true;
    int ans = 24, bef = 0;
    for(int i = 1; i <= 24; i++){
        if(best[i]){
            ans = min(ans, i-bef);
            bef = i;
        }
    }
    cout << ans << endl;
    return 0;
}