#include <bits/stdc++.h>
using namespace std;

long long int sum(int a, int b){
    long long int sum=0;
    while(a > 0){
        sum += a % 10;
        a /= 10;
    }

    while(b > 0){
        sum += b % 10;
        b /= 10;
    }
    return sum;
}

int main(){
    int n, a=1, b;
    long long int menorsum=1000000000;
    cin >> n;
    b = n-1;
    
    while(b > 0){
        if(sum(a, b) < menorsum) menorsum = sum(a, b);
        a++;
        b--;
    }

    cout << menorsum << endl;
    return 0;
}