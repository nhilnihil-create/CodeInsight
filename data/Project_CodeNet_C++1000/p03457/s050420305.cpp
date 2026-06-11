#include <bits/stdc++.h>
using namespace std;
 
int main() {
    int n;
    cin >> n;
    string ans="Yes";
    vector<int> t(n), x(n), y(n);
    for(int i=0; i<n; i++){
        cin >> t.at(i);
        cin >> x.at(i);
        cin >> y.at(i);
    }
    for(int i=0; i<n; i++){
        int dt, dx, dy;
        if(i == 0){
            dt = abs(t.at(i));
            dx = abs(x.at(i));
            dy = abs(y.at(i));
        }else{
            dt = abs(t.at(i) - t.at(i-1));
            dx = abs(x.at(i) - x.at(i-1));
            dy = abs(y.at(i) - y.at(i-1));
        }
        if(dt >= (dx+dy) && (dt-(dx+dy))%2==0){
        }else{
            ans="No";
            break;
        }
    }
    cout << ans;

}