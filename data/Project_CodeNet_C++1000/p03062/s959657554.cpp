#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
using namespace std;
#define rep(i, a, b) for(long long i = a; i < (b); ++i)
typedef long long ll;
 
int main() {
    int N;
    cin >> N;
    vector<long long>A(N);
    rep(i, 0, N){
        cin >> A[i];
    }
    int minasuC = 0;
    long long sum = 0;
    long long minA = 10000000000;
    rep(i, 0, N){
        if(A[i] < 0){
            minasuC++;
        }
        minA = min(abs(A[i]),minA);
        sum += abs(A[i]);
    }
    if(minasuC%2){
        sum = sum-minA*2;
    }
    cout << sum << endl;
    return 0;
}
