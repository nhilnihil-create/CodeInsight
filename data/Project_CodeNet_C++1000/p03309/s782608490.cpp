#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


void func() {
    int N;
    cin >> N;
    vector<long  long> arr = vector<long long>(N,0);
    long  long sum = 0;
    for (int i = 1; i <= N; ++i) {
        int a;
        cin >> a;
        arr[i - 1] = a - i;
        sum += a - i;
    }
    sort(arr.begin(),arr.end());
    long long currentSum = 0;
    long long target = INT64_MAX;

    for (int j = 0; j < N; ++j) {
       target = min(target,j * arr[j] - currentSum + (sum - currentSum - arr[j] * (N - j)));
       currentSum += arr[j];
    }


    cout << target << endl;
}
int main() {
    func();
    return 0;
}
