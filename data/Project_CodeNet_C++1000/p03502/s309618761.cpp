#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main(){
    int N;
    int sum=0;
    int remainder = 0;
    cin >> N;
    int n = N;
    
    while(n > 0){
        remainder = n % 10;
        sum += remainder;
        n /= 10;
    }

    if (N % sum == 0){
        cout << "Yes" << endl;
    }
    else
    {
        cout << "No" << endl;
    }
    
}