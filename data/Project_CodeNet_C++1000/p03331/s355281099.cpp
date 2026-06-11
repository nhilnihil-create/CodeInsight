#include<iostream>
#include<string>
using namespace std;
int main() {
    int N;
    cin >> N;
    int min = 100;
    for(int i = 1; i < N; i++){
        int A = i;
        int B = N - i;
        int ta = A;
        int tb = B;
        int sum = 0;

        for(int j = 0; j < 5; j++){
            sum += ta % 10 + tb % 10;
            ta /= 10;
            tb /= 10;
        }

        if(min > sum) min = sum;

    }
    cout << min << endl;
    return 0;
}