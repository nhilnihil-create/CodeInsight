#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <queue>
using namespace std;

int N, n;

struct BIT {
    vector<int> bit;
    int M;
    
    BIT(int M): bit(vector<int>(M + 1)), M(M) { }
    
    int sum(int i) {
        int s = 0;
        while (i > 0) {
            s += bit[i];
            i -= i & -i;
        }
        return s;
    }
    void add(int index, int x) {
        while (index <= M) {
            bit[index] += x;
            index += index & -index;
        }
    }
};

long long inversion_number(vector<int>& A, int Maximum) {  //数列の転倒数
    long long ans = 0;
    int p = 1, n = (int) A.size();
    while (p < Maximum) {
        p = p << 1;
    }
    BIT b(p);
    for (int i = 0; i < n; i++) {
        ans += i - b.sum(A[i]);
        b.add(A[i], 1);
    }
    return ans;
}

bool judge(int x, vector<int>& A) {
    vector<int> S(N + 1);
    S[0] = N + 1;
    long long j = 1ll * N * (N + 1) / 2 / 2;
    for (int i = 0; i < N; i++) {
        if (A[i] < x) {
            S[i + 1] = S[i] - 1;
        } else {
            S[i + 1] = S[i] + 1;
        }
    }
    return inversion_number(S, 2 * N + 1) <= j;
}

int bin_search(int left, int right, vector<int>& A) {
    if (left + 2 > right) {
        return judge(right, A)? right: left;
    }
    
    int mid = (left + right) / 2;
    if (judge(mid, A)) {
        return bin_search(mid, right, A);
    } else {
        return bin_search(left, mid, A);
    }
}

int main() {
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; i++) cin >> A[i];
    
    cout << bin_search(1, 1e9, A) << endl;
}