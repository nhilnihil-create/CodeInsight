#include <iostream>
#include <string>

using namespace std;

bool test(int n){
    int pre = n%10;
    n /= 10;
    while(n != 0){
        if(pre != n%10) return false;
        n /= 10;
    }
    return true;
}

int main(){
    int n;
    cin >> n;
    while(1){
        if(test(n)){
            cout << n << endl;
            break;
        }
        n++;
    }
}