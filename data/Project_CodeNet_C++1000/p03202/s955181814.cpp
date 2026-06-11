#include <iostream>
#include <vector>
#include <map>
using namespace std;

int N;

bool judge(int K, vector<int>& A) {
    map<int, int> mp;
    int temp = A[0];
    for (int i = 1; i < N; i++) {
        int prev = temp;
        temp = A[i];
        if (prev >= temp) {
            if (K == 1) return false;
            auto itr = mp.lower_bound(temp);
            if (itr != mp.end()) {
                mp.erase(itr, mp.end());
            }
            int j = temp - 1;
            while (mp[j] == K - 1) {
                mp.erase(j);
                j--;
                if (j < 0) return false;
            }
            mp[j]++;
        }
    }
    return true;
}

int binary(vector<int>& A, int left, int right) {
    if (left == right) {
        return left;
    }
    
    int mid = (left + right) / 2;
    
    if (judge(mid, A)) {
        return binary(A, left, mid);
    } else {
        return binary(A, mid + 1, right);
    }
}


int main() {
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    cout << binary(A, 1, N) << endl;
}