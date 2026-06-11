#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

int main(){
    int N;
    cin >> N;
    long long A[N];
    for(int i =0; i < N; i++){
        cin >> A[i];
    }
    long long  g = A[0];
    for(int i = 1; i < N; i++){
        g = __gcd(A[i],g);
    }
    cout << g << endl;
}