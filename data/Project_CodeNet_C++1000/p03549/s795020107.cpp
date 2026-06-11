#include <iostream>
using namespace std;





int main() {
    long long N, M;
    cin >> N >> M;
    long long teisyutu_kaisuu = 1LL<<M;
    long long each_time = 1900LL * M + 100LL * (N - M);
    cout <<  each_time * teisyutu_kaisuu << endl;
}