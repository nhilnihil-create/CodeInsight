#include <bits/stdc++.h>
using namespace std;

int main(){

    vector<int> order_time(5);
    int min_mod = 1e5, pos = 0;

    for (int i=0; i<5; i++){
        cin >> order_time.at(i);

        int mod_temp;
        mod_temp = order_time.at(i)%10;

        if (mod_temp != 0){
            min_mod = min(mod_temp, min_mod);
            
            if (mod_temp == min_mod){
                pos = i;
            }
        }
    }

    int ans = 0;
    for (int i=0; i<5; i++){
        if (i == pos) ans += order_time.at(i);
        else if (order_time.at(i)%10 == 0) ans += order_time.at(i);
        else ans += (order_time.at(i) + (10 - order_time.at(i)%10));
    }

    cout << ans << endl;
    return 0;
}