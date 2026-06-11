#include <bits/stdc++.h>
using namespace std;
vector<int> x, y, z;

void push(int a, int b, int c) {
    x.push_back(a);
    y.push_back(b);
    z.push_back(c);
}

void ans() {
    cout << 20 << " " << x.size() << endl;
    for (int i = 0; i < x.size(); i++) {
        cout << 20 - x[i] << " " << 20 - y[i] << " " << z[i] << endl;
    }
}

int main() {
    int L; cin >> L;
    bool flag = false;
    int cnt = 0;
    vector<int> c(20, 0);
    for (int i = 0; i <= 19; i++) {
        c[i] = (1 << i);
        if (i < 19) push(i+1, i, 0);
    }
    int max_k = -1;
    while (cnt < L) {
        int k; 
        for (k = 0; k < 19; k++) {
            if (cnt + c[k+1] > L) {
                break;
            }
        }
        if (cnt == 0) max_k = k+1;
        else push(19, k, cnt);
        cnt += c[k];
    }
    for (int i = 0; i < max_k-1; i++) {
        push(i+1, i, (1 << i));
    }
    ans();
    return 0;
}