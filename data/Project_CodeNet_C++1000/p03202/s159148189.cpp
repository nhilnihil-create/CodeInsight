#include <bits/stdc++.h>
using namespace std;

const int N = 200010;

typedef pair<int, int> P;

int A[N], n;

inline bool check(int mid) {
    set<P> s;
    for (int i = 2; i <= n; i++) if (A[i] <= A[i - 1]) {
        while (s.size() && s.rbegin() -> first > A[i]) s.erase(*s.rbegin());
        for (int j = A[i]; ; j--) {
            if (!j) return false;
            if (s.size() && j == s.rbegin() -> first) {
                if (s.rbegin() -> second < mid - 1) {
                    auto t = *s.rbegin(); s.erase(t), t.second++;
                    s.insert(t); break;    
                } else s.erase(*s.rbegin());
            } else {
                if (mid == 1) return false;
                s.insert(P(j, 1)); break;
            }
        } 
    }
    return true;
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", &A[i]);
    int l = 1, r = n, mid, ans = -1;
    while (l <= r) {
        mid = (l + r) >> 1;
        if (check(mid)) r = mid - 1, ans = mid;
        else l = mid + 1;
    }
    printf("%d\n", ans);
}