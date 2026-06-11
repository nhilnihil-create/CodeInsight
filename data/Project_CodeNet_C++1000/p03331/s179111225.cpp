#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;

int SumOfDigit(int n){
    int sum = 0;
    while(n>0){
        sum += n%10;
        n /= 10;
    }

    return sum;
}

int main(){
    int N;
    cin >> N;

    int min = 1145141919;

    for(int i = 1; i < N; i++){
        int a = i;
        int b = N-a;

        int suma = SumOfDigit(a);
        int sumb = SumOfDigit(b);

        int sum = suma + sumb;

        if(min > sum) min = sum;
    }

    cout << min << endl;
}