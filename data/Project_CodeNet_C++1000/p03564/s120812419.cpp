#include <iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
    int n, k,result=1;
    cin >> n >> k;
    int x = floor(log2(k))+1;
    if (x < n) {
        result *= pow(2, x);
        result += (n - x) * k;

    }
    else { result *= pow(2, n); }
    cout << result;
}