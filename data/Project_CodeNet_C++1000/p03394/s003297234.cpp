#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <queue>
using namespace std;

int N;

int main() {
    cin >> N;
    if (N == 3) {
        cout << 2 << " " << 5 << " " << 63 << endl;
      return 0;
    }
    vector<int> S = {2, 3, 4, 9};
    if (N % 2) S.push_back(6);
    vector<pair<int, int>> A;
    for (int i = 0; 10 + 6 * i < 30000 ; i++) {
        A.push_back(make_pair(8 + 6 * i, 10 + 6 * i));
    }
    for (int i = 0; 21 + 12 * i < 30000 ; i++) {
        A.push_back(make_pair(15 + 12 * i, 21 + 12 * i));
    }
    for (int i = 0; 18 + 12 * i < 30000; i++) {
        A.push_back(make_pair(12 + 12 * i, 18 + 12 * i));
    }
    sort(A.begin(), A.end());
    
    for (int i = 0; i < A.size(); i++) {
        if (S.size() == N) break;
        S.push_back(A[i].first); S.push_back(A[i].second);
    }
    if (S.size() < N) {
      S.push_back(30000);
      S.push_back(6);
    }
    
    for (int i = 0; i < S.size(); i++) {
        cout << S[i] << " ";
    }
    cout << endl;
}
