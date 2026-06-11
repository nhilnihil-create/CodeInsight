#include <bits/stdc++.h>

using namespace std;
//using ll = long long;

//cout << std::fixed << std::setprecision(15) << y << endl;

int main() {
    int n = 0;
    cin >> n;
    if(n < 105){
        cout << 0 << endl;
        return 0;
    }
    int r = 0;
    for(int i = 105;i <= n;i += 2){
        int cnt = 0;
        for(int j = 1;j * j < i;j++){
            if(i % j == 0){
                //cout << j << endl;
                cnt++;
                if(i / j != j){
                    //cout << j << endl;
                    cnt++;
            }
            }
        }
        //cout << cnt << endl;
        if(cnt == 8){
            r++;
        }
    }
    cout << r << endl;
    return 0;
}