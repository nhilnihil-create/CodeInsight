#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++);
using namespace std;
using ll = long long;
using P = pair<int, int>;
 
int main() {
    int N, A, B;
    cin >> N >> A >> B;
 
    int total_sum = 0;
    for (int i = 0; i <= N; ++i) {
        int number = i;
        int sum = 0;
 
        while (number != 0) {
            sum += number % 10;
            number = number / 10;
        }
 
        if (sum >= A && sum <= B) {
            total_sum += i;
    
        }
    }
    cout << total_sum << endl;
}