#include <iostream>
#include <cmath>
using namespace std;
int main(){
    int x; cin >> x;
    int ans = 1;
    for(int b = 2; b < x+1; b++){
        int power = b*b;
        while(1){
            if(x < power) break;
            ans = max(ans, power);
            power *= b;
        }
    }
    cout << ans << endl;
    return 0;
}