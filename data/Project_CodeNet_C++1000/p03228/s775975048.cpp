#include <iostream>

using namespace std;


int main(){
    long long A, B; cin >> A >> B;
    int K; cin >> K;

    for (int i = 0; i < K; i++){
        if (i % 2 == 0){
            A = A / 2;
            B = A + B;
        }else{
            B = B / 2;
            A = A + B;
        }
    }
    
    cout << A << " " << B << endl;

    return 0;
}