#include <iostream>
#include <string>
using namespace std;

int main(){
    int N;
    cin >> N;

    int A[N];
    for(int i = 0; i < N; i++) {
        cin >> A[i];
    }

    bool evan = true;
    int c = 0;
    while(evan) {
        // 偶数かどうかチェック
        for(int i = 0; i < N; i++) {
            if(A[i] % 2 != 0) {
                evan = false;
                break;
            }
        }

        if(!evan) {
            break;
        }
      
        for(int i = 0; i < N; i++) {
            A[i] = A[i] / 2;
        }

        c++;
    }

    cout << c << endl;
}
