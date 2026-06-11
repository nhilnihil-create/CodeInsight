#include <iostream>
#include <vector>
#include <cmath>
typedef unsigned long long ll;
using namespace std;


int main(void) {
    int ary[5];
    for (int i = 0; i < 5; i++) cin >> ary[i];
    
    int max_loss = 0;
    int max_loss_idx = 0;
    for (int i = 0; i < 5; i++){
        if((ary[i] % 10 != 0) && (10 - ary[i] % 10) > max_loss){
            max_loss_idx = i;
            max_loss = 10 - ary[i] % 10;
        }
    }

    int ans = 0;
    for (int i = 0; i < 5; i++){
        if (i == max_loss_idx)
            continue;
        if (ary[i] % 10 == 0) {
            ans += ary[i];
        }else{
            ans += ((ary[i]+10) / 10) * 10;
        }
    }
    ans += ary[max_loss_idx];
    cout << ans << endl;
    
    return 0;
}