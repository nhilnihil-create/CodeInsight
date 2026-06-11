#include <iostream>


using namespace std;

int main() {
    int N,i,sum;

    cin >> N;
    i = N;
    while(i > 0){
        sum += i % 10;
        i /= 10;
    }

    if(N % sum == 0){
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
    return 0;
}