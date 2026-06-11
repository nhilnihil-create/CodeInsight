#include <iostream>
#include <vector>
#include <cstdint>
using namespace std;
typedef int64_t i64;
vector<i64> L(87);

i64 lucas(int n){
    if(n == 0) return 2;
    if(n == 1) return 1;
    if(L[n] == 0) L[n] = lucas(n-1) + lucas(n-2);
    return L[n];
}

int main(void){
    int n;
    cin >> n;
    cout << lucas(n) << '\n';
    return 0;
}