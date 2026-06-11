#include <iostream>

using namespace std;

int main(){
    int n;
    cin >> n;
    for(int i = 0; i < 1000000001; i++){
        if(i * i > n){
            cout << (i - 1) * (i - 1);
            break;
        }
    }
    cout << "" << endl;
    return 0;
}