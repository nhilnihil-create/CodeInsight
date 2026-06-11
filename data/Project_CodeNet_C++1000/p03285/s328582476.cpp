#include <iostream>
using namespace std;

int main(void){
    int N;
    cin >> N;
    for(int i = 0; i <= 25 ;i++){
        for(int j = 0; j < 16 ;j++){
            if(4*i + 7*j == N){
                cout << "Yes" << endl;
                return 0;
            }
        }
    }
    cout << "No" << endl;
    return 0;
}