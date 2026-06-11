#include <bits/stdc++.h>
using namespace std;

int main(){
    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; i++){
        int x;
        cin >> x;
        A.at(i) = x - i - 1;
    }
    sort(A.begin(), A.end());
    
    int b = A.at(N / 2);
    int64_t ans = 0;
    for (int i = 0; i < N; i++){
        ans += abs(b - A.at(i));
    }
    cout << ans << endl;
}

