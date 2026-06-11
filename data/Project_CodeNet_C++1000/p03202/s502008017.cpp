#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// k文字でいけるならtrue
bool C(int k, vector<int> A){
    stack<pair<int, int>> st;
    if(k == 1) {
        for (int i = 1; i < A.size(); ++i) {
            if(A[i-1] >= A[i]) return false;
        }
        return true;
    }
    
    for (int i = 1; i < A.size(); ++i) {
        if(A[i-1] >= A[i]){
            if(A[i-1] != A[i]){
                while (! st.empty() && st.top().first > A[i]) st.pop();
            }
            int cur = A[i]; // 1を足す桁
            while (1){
                if(st.empty() || st.top().first < cur) st.push({cur, 0});
                if(st.top().second < k-1) {
                    st.top().second++;
                    break;
                } else{
                    st.pop();
                    cur--;
                    if(cur <= 0) return false;
                }
            }
        }
    }
    return true;
}

int main() {
    int N;
    cin >> N;
    vector<int>A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    int lb = 0, ub = 1000000007;
    while( ub-lb > 1 ){
        int mid = (lb + ub)/2;
        if(C(mid, A)){
            ub = mid;
        }else{
            lb = mid;
        }
    }
    cout << ub;
    return 0;
}