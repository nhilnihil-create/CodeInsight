#include <bits/stdc++.h>
using namespace std;

int main(void){
    int N; cin >> N;
    if (N == 3) {
        cout << "2 5 63" << endl;
        return 0;
    }
    
    vector<int> A;
    vector<int> B;
    vector<int> C;
    for (int i = 2; i <= 30000; i++) {
        if (i % 6 == 0) C.push_back(i);
        else if (i % 2 == 0) A.push_back(i);
        else if (i % 3 == 0) B.push_back(i);
    }
    
    vector<int> ans;
    ans.push_back(2);
    ans.push_back(4);
    ans.push_back(3);
    ans.push_back(9);
    N -= 4;
    for (int i = 3; i < A.size() && 2 <= N; i += 2) {
        ans.push_back(A[i]);
        ans.push_back(A[i-1]);
        N -= 2;
    }
    for (int i = 3; i < B.size() && 2 <= N; i += 2) {
        ans.push_back(B[i]);
        ans.push_back(B[i-1]);
        N -= 2;
    }
    for (int i = 0; i < C.size() && 0 < N; i++) {
        ans.push_back(C[i]);
        N--;
    }
    for (auto i : ans) {
        cout << i << " ";
    }
    cout << endl;
}
