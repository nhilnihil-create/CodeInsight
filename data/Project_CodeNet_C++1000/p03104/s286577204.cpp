#include<iostream>

using namespace std;

long long f(long long x){
    if(x <= 0) return 0;
    if(x%2 == 1){
        if(x%4 == 1) return 1;
        else return 0;
    }
    return (x ^ f(x-1));
}
int main(){
    long long a, b;
    cin >> a >> b;
    cout << (f(b) ^ f(a-1));
}
