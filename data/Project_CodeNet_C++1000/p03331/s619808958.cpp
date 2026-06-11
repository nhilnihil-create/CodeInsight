#include <iostream>
#include <algorithm>
using namespace std;

int findSum(int n){
    int sum = 0;
    while (n > 0){
        sum += n % 10;
        n /= 10;
    }
    return sum;
}

int main(){
    int N;
    cin >> N;
    int min=1000000;
    for (int i=1; i<N; i++){
        int A = i;
        int B = N - A;
        int S = findSum(A) + findSum(B);
        if (min > S){
            min = S;
        }
    }
    cout << min << endl;
    return 0;
}
