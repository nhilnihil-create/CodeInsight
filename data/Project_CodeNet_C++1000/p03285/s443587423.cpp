#include <iostream>

using namespace std;

int main(){
    int N;
    bool flag = false;
    cin >> N;
    for(int i = 0; i <= 25; i++){
        for(int j = 0; j <= 14; j++){
            if(4 * i + 7 * j == N) flag = true;
        }
    }
    if(flag) cout << "Yes" << endl;
    else cout << "No" << endl;
}