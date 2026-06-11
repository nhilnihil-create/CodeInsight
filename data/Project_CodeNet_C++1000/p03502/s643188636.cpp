#include <bits/stdc++.h>
using namespace std;

int main(){
    long long n;
    long long temp;
    cin >> n;
    temp = n;
    int sum=0;

    while(temp){
        sum += temp % 10;
        temp /= 10;
    }

    if(n % sum == 0){
        cout << "Yes" << endl;
    }
    else {
        cout << "No" << endl;
    }
}