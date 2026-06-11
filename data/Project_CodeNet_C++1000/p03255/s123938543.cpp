#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, X;

long long cost(vector<long long> S, int k) {  //ゴミ捨てk回でかかるコスト
    long long cost = 5 * (S[N] - S[N - k]);
    for (int i = 1; i * k < N ; i++) {
        int j = max(N - (i + 1) * k, 0);
        cost += (2 * i + 3) * (S[N - i * k] - S[j]);
    }
    return cost + 1ll * k * X;
}

long long binary(vector<long long> S, int left, int right) {
    if (left + 2 > right) {
        return min(cost(S, left), cost(S, right));
    }
    
    int mid = (left + right) / 2;
    
    long long lcost = cost(S, left);
    long long mcost = cost(S, mid);
    long long rcost = cost(S, right);
    if (lcost <= mcost && mcost <= rcost) {
        return binary(S, left, mid);
    } else if (lcost >= mcost && mcost >= rcost) {
        return binary(S, mid, right);
    } else {
        return min(binary(S, left, mid), binary(S, mid, right));
    }
}

int main() {
    cin >> N >> X;
    vector<long long> S(N + 1, 0);   //座標の累積和
    for (int i = 0; i < N; i++) {
        int x;
        cin >> x;
        S[i + 1] = S[i] + x;
    }
    
    cout << binary(S, 1, N) + 1ll * N * X << endl;
}