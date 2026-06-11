#include <iostream>
using namespace std;
int main(){
    int a[5];
    for(int i = 0; i < 5; i++)cin >> a[i];
    int temp = 9;
    int ind = 0;
    for(int i = 0; i < 5; i++){
        if(temp > a[i] % 10 && a[i] % 10 != 0){
            ind = i;
            temp = a[i] % 10;
        }
    }
    int ans = 0;
    for(int i = 0; i < 5; i++){
        if(i != ind) ans += (a[i] + 9) / 10 * 10;
        else ans += a[i];
    }
    cout << ans << endl;
}