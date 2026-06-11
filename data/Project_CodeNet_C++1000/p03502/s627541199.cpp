#include<iostream>
#include<string>
#include<vector>
#include <algorithm>
using namespace std;

int find_sumation_individual_digits(int n){
    int sum = 0;
    while(n > 0){
        sum = sum + (n % 10);
        n = n / 10;
    }
    return sum;
}

int main() {
    int N ;
    cin >> N ;
    int f_N = find_sumation_individual_digits(N) ;
    if( (N % f_N) == 0){
        cout << "Yes" << endl;
    }
    else {
        cout << "No" << endl;
    }
}