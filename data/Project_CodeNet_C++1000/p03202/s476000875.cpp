#include<bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;

const int MN = 200010;

int N;
int A[MN];
set<pii> st;

bool check(int x) {
    st.clear();
    for(int i = 1; i < N; i++) {
        if(A[i - 1] < A[i]) {
            continue;
        }
        else {
            int pos = A[i];
            while(pos) {
                auto it = st.lower_bound(pii(pos, -1));
                if(it == st.end()) {
                    st.insert(pii(pos, 1));
                    break;
                }
                pii t = *it; st.erase(t);
                if(pos < t.first) {
                    st.insert(pii(pos, 1));
                    break;
                }
                if(t.second == x - 1) {
                    pos--;
                    continue;
                }
                t.second++;
                st.insert(t);
                break;
            }
            if(!pos) return false;
            while(st.size() && st.rbegin()->first > pos) {
                st.erase(*st.rbegin());
            }
        }
    }
    return true;
}

int main() {
    scanf("%d", &N);

    for(int i = 0; i < N; i++) {
        scanf("%d", &A[i]);
    }

    bool ok = true;
    for(int i = 1; i < N; i++) {
        if(A[i - 1] >= A[i]) {
            ok = false;
            break;
        }
    }
    if(ok) {
        printf("1");
        return 0;
    }

    int s = 2, e = N, p = -1;
    while(s <= e) {
        int m = (s + e)>>1;

        if(check(m)) {
            p = m;
            e = m - 1;
        }
        else s = m + 1;
    }
    printf("%d", p);
}
