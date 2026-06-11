#include <bits/stdc++.h>
using namespace std;

int main(){
    int n; cin >> n;
    vector<int> x(n), y(n), h(n);
    int idx;
    for(int i = 0; i < n; i++){
        cin >> x.at(i) >> y.at(i) >> h.at(i);
        if(h.at(i) != 0) idx = i;
    }
    int H;
    bool ok;
    for(int i = 0; i <= 100; i++){
        for(int j = 0; j <= 100; j++){
            ok = true;
            H = abs(i - x.at(idx)) + abs(j - y.at(idx)) + h.at(idx);
            for(int k = 0; k < n; k++){
                if(h.at(k) != max(H - abs(i - x.at(k)) - abs(j - y.at(k)), 0)) ok = false;
            }
            if(ok){
                cout << i << " " << j << " " << H;
                break;
            }
        }
        if(ok) break;
    }
}