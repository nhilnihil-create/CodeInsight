#include<iostream>
using namespace std;

int main(){
    int x;
    cin >> x;
    int ans = 1;
    for(int i = 2; i*i <= x; i++){
        int tmp = i*i;
        while(tmp <= x){
            ans = max(ans, tmp);
            tmp *= i;
        }
    }
    cout << ans << endl;
    return 0;
}