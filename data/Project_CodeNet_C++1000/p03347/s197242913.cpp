#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>
#include <map>
#include <queue>
using ll = long long;
using graph = std::vector<std::vector<ll>>;

using namespace std;

int main() {
    ll N;
    cin >> N;
    ll A[N];
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
        if(i == 0){
            if(A[0] != 0) {
                cout << -1 << endl;
                return 0;
            }
        }else{
            if(A[i] - A[i-1] > 1){
                cout << -1 << endl;
                return 0;
            }
        }
    }
    ll currentStep = A[N - 1];
    ll sum = A[N - 1];
    for (int i = 1; i < N; ++i) {
        if(currentStep != 0){
            currentStep--;
        }
        if(currentStep < A[N - i - 1]){
            currentStep = A[N - i - 1];
            sum += A[N - i - 1];
        }
    }
    cout << sum << endl;

}
