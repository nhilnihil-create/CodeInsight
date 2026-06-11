#include <bits/stdc++.h>

using namespace std;

const int MAX = 2e5+5;

int N;
int A[MAX];

bool check(int x) {
    vector< pair<int,int> > S;
    for(int i=0; i<N-1; i++) {
        if(A[i+1] > A[i]) {
            continue;
        }
        if(x <= 1) {
            return false;
        }
        int a = A[i+1];
        while(S.size() && (*(S.end()-1)).first > a) {
            S.pop_back();
        }
        if(S.size() && (*(S.end()-1)).first == a) {
            (*(S.end()-1)).second++;
        }
        else {
            S.push_back({a, 1});
        }
        while((*(S.end()-1)).second == x) {
            int d = (*(S.end()-1)).first;
            if(d == 1) {
                return false;
            }
            S.pop_back();
            if(S.size() && (*(S.end()-1)).first == d-1) {
                (*(S.end()-1)).second++;
            }
            else {
                S.push_back({d-1,1});
            }
        }
    }
    return true;
}

int main() {
    cin >> N;
    for(int i=0; i<N; i++) {
        cin >> A[i];
    }

    int L = 1, R = N;
    while(L != R) {
        int mid = (L + R) >> 1;
        if(check(mid)) {
            R = mid;
        }
        else {
            L = mid+1;
        }
    }

    cout << L << "\n";

    return 0;
}
