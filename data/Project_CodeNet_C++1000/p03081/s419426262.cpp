#include <iostream>
#include <map>
#include <vector>
#include <tuple>

using namespace std;

int N, Q;
string s;
vector<char> t;
vector<char> d;

int calc(int target) {
    int index = target;
    for (int i = 0; i < Q; i++) {
        char c = s[index];
        if (t[i] == c) {
            if (d[i] == 'L') index--;
            else index++;

            if (index == -1) return index;
            else if (index == N) return index;
        }
    }
    return target;
}

int findL(int l, int r) {
    while (l <= r) {
        int mid = (l+r)/2;
        if (calc(mid) == -1) {
            // if (calc(mid+1) == mid+1) return mid + 1;
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    return l;
}

int findR(int l, int r) {
    while (l <= r) {
        int mid = (l+r)/2;
        if (calc(mid) == N) {
            // if (calc(mid-1) == mid-1) return mid - 1;
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    return r;
}

int main() {
    cin >> N >> Q;
    cin >> s;

    for (int i = 0; i < Q; i++) {
        char tt, dd;
        cin >> tt >> dd;
        t.push_back(tt);
        d.push_back(dd);
    }

    if (calc(N-1) == -1 || calc(0) == N) {
        cout << 0 << endl;
        return 0;
    }

    int l = findL(-1, N);
    int r = findR(-1, N);

    // if (l == -1) l = 0;
    // if (r == -1) r = N - 1;

    cout << r - l + 1 << endl;

    return 0;
}
