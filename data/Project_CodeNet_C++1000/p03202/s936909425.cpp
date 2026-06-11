#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 2e5 + 10;

int N, A[MAX_N];

bool check(int sigma) {
    static pair<int, int> stk[MAX_N];
    int top = 0;
    for (int i = 1; i <= N; i++) {
        int delta = A[i] - A[i - 1];
        if (delta > 0) {
            stk[++top] = make_pair(1, delta);
        } else {
            while (delta) {
                if (delta + stk[top].second <= 0) {
                    delta += stk[top].second;
                    top--;
                } else {
                    stk[top].second += delta;
                    delta = 0;
                }
            }
            int popped = 0;
            while (top && stk[top].first == sigma) {
                popped += stk[top].second;
                top--;
            }
            if (!top) return false;
            if (stk[top].second != 1) {
                stk[top + 1] = make_pair(stk[top].first, 1);
                stk[top].second--;
                top++;
            }
            stk[top].first++;
            if (popped) {
                stk[++top] = make_pair(1, popped);
            }
        }
    }
    return true;
}

int main() {
    scanf("%d", &N);
    for (int i = 1; i <= N; i++) scanf("%d", &A[i]);
    int l = 1, r = N;
    while (l != r) {
        int m = (l + r) / 2;
        if (check(m)) r = m;
        else l = m + 1;
    }
    printf("%d\n", l);
}
