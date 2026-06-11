#include <iostream>
#include <string>
#include <cmath>
#include <ctime>
#include <vector>
#include <algorithm>
#include <cstdlib>
using namespace std;

int findSumOfDigits(int n) {
    int sum = 0;
    while (n > 0) { // n が 0 になるまで
        sum += n % 10;
        n /= 10;
        }
return sum;
}

int main(){
    int N;
    cin >> N;
    int min = 1000000;
    int temp;

    for(int a = 1; a < N; a++){
        int b = N - a;

        temp = findSumOfDigits(a) + findSumOfDigits(b);
        if(min > temp) min = temp;

    
    }

    cout << min << endl;


}