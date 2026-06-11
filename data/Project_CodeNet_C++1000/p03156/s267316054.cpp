#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int N, A, B;
    cin >> N >> A >> B;
    vector<int>P(N);
    for (int i = 0; i < N; ++i) {
      cin >> P[i];
    }
    vector<int>stock(3, 0);
    for (int i = 0; i < N; ++i) {
        if(P[i] <= A) {
            stock[0]++;
        } else if(P[i] > B){
            stock[2]++;
        } else{
            stock[1]++;
        }
    }
    sort(stock.begin(), stock.end());
    cout << stock[0];
    return 0;
}