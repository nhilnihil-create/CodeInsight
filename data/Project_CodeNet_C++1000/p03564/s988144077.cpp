#include <iostream>
using namespace std;

int main(){
    int n, k;
    cin >> n;
    cin >> k;
    int ans = 1001001001;
    for(int bit = 0; bit < (1 << n); bit++){
        int coans = 1;
        for(int i = 0; i < n; i++){
            if(bit & (1 << i)){
                coans <<= 1;
            }else{
                coans += k;
            }
        }
        if(ans > coans) ans = coans;
    }
    cout << ans << endl;
    return 0;
}