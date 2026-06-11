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
    int N,A ,B;
    cin >> N >> A >> B ;
    int sumation=0;
    for(int i=1; i<=N;i++){
        int dig_sum = find_sumation_individual_digits(i) ;
        if( (A <= dig_sum)&&( dig_sum <= B)){
            sumation = sumation + i;
        }
    }
    cout << sumation << endl;
}