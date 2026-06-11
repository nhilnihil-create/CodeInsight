#include <iostream>
using namespace std;

int main(){
    long long x, y;cin>>x>>y;
    if (x % y == 0){
        cout << -1 << endl;
    } else {
        long long num=1;
        bool success_flag = true;
        while(true){
            if (x * num <= 1000000000000000000){
                if (x * num % y != 0){
                    break;
                }
            } else {
                success_flag = false;
                break;
            }
        }
        if (success_flag){
            cout << x * num <<endl;
        } else {
            cout << -1 << endl;
        }
    }
    return 0;
}