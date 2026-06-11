#include <iostream>
#include <vector>
#include <cmath>
typedef unsigned long long ll;
using namespace std;

int main(void) {
    int N; cin >> N;
    ll L[90];
    
    L[0] = 2;
    L[1] = 1;
    for(int i = 2; i <= N; i++) L[i] = L[i-2] + L[i-1];
    cout << L[N] << endl;
    return 0;
}