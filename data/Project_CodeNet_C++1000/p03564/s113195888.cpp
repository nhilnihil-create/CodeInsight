#include <iostream>
using namespace std;
int main(void){
    int N;
    int K;
    cin >> N >> K;
    int x =1;
    for (int i=0; i<N; i++){
        if(2 * x < x + K){
            x = 2*x;
        }
        else if(2 * x >= x + K){
            x += K;
        }
    }
    cout << x << endl;
}
