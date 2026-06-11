#include <iostream>
using namespace std;

int main(){
    int n;
    cin >> n;
    int num[4];
    for(int i = 0; i < 4; i++){
        num[i] = n % 10;
        n /= 10;
    }

    if((num[0] == num[1] && num[1] == num[2]) || (num[1] == num[2] && num[2] == num[3])){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }
    return 0;
}