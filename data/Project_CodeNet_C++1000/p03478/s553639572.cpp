
#include <bits/stdc++.h>
#include <algorithm>
#include <iostream>
using namespace std;    
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int sum_of_digits(int n){
    int sum = 0;
    while(n>0){
        sum += n%10;
        n/=10;
    }
    return sum;
}

int main() {
    int n, a, b;
    cin >> n >> a >> b;
    int total = 0;
    for (int i=0; i<=n; i++){
        int sum = sum_of_digits(i);
        if (sum >= a && sum <=b){
            total +=i;
        }
    }
    cout << total << endl;
}