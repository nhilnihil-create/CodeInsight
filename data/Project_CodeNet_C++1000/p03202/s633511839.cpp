#include <bits/stdc++.h>
using namespace std;
int N;
int A[200000];

bool judge(int X) {
    stack<pair<int, int>> S;
    for(int i=1; i<N; ++i) {
        if(A[i - 1] >= A[i]) {
            while(S.size() && S.top().first > A[i]) S.pop();
            if(S.size() && S.top().first == A[i]) {
                ++S.top().second;
            } else {
                S.push({A[i], 1});
            }
            while(S.top().second == X) {
                int d = S.top().first;
                if(d == 1) return false;
                S.pop();
                if(S.size() && S.top().first == d - 1) {
                    ++S.top().second;
                } else {
                    S.push({d - 1, 1});
                }
            }
        }
    }
    return true;
}

int main() {
    cin >> N;
    bool flag = true;
    for(int i=0; i<N; ++i) {
        cin >> A[i];
        if(i > 0 && A[i-1] >= A[i]) flag = false;
    }

    if(flag) {
        cout << 1 << endl;
        return 0;
    }

    int l = 1, r = N;
    while(r - l > 1) {
        int m = (l + r) / 2;
        if(judge(m)) r = m;
        else l = m;
    }
    cout << r << endl;
}