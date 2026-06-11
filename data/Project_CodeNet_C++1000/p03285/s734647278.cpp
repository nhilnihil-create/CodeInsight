#include <iostream>
#include <string>
#define Max 50
using namespace std;

int main() {
    int N,flg = 0;
    cin >> N;
    for(int a = 0; a < N; a++){
        for(int b = 0; b < N; b++){
            if(a * 4 + b * 7 == N) {
                flg = 1;
                break;
            }else{
                flg = 0;
            }
        }
        if(flg == 1)break;
    }
    
    if(flg == 1){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }
    
}
