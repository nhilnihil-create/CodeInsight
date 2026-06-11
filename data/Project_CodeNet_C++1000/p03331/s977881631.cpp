#include <bits/stdc++.h> 
using namespace std; 

int main() { 
    int n; 
    cin >> n; 

    int sum = 0; 
    while (n) {
        sum += n % 10; 
        n = n/10; 
    }

    sum == 1 ? cout << 10 : cout << sum; 

}