#include <iostream>
#include <iomanip>
#include <algorithm>
#include <cmath>

using namespace std;
#define N 1000000

int* Eratosthenes(){
    int* arr = new int[N];

    for(int i = 0; i < N; i++){
        arr[i] = 1;
    }
    for(int i = 2; i < sqrt(N); i++){
        if(arr[i]){
            for(int j = 0; i * (j + 2) < N; j++){
                arr[i *(j + 2)] = 0;
            }
        }
    }

    for(int i = 2; i < N; i++){
        if(arr[i]){
        }
    }

    return arr;
}


int main(){

    long n, p;
    cin >> n >> p;
    int* arr;

    int ans = 1;

    if (n == 1) {
        cout << p << endl;
        return 0;
    } else {
        arr = Eratosthenes();
        for (int i=2; i<=N; i++) {
            if (arr[i]) {
                int count = 0;
                while (p%i == 0) {
                    count++;
                    p /= i;
                }
                if (count/n) {
                    ans *= pow(i, count/n);
                }
            }
            if (p == 1) {
                break;
            }
        }
        cout << ans << endl;

        return 0;
    }
}
