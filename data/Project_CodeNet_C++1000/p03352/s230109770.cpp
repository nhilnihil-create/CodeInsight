#include <iostream>
using namespace std;

int main(){
    int x;
    cin >> x;
    int ans = 1;
    for(int i = 2; i*i <= x; i++){
        int coans = i*i;
        for(int j = 2; coans <= x; j++){
            if(coans > ans) ans = coans;
            coans *= i;
        }
    }
    cout << ans << endl;
    return 0;
}