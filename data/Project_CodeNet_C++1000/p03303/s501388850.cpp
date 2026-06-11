#include <bits/stdc++.h>
using namespace std;

int main(int, char**) {
        string S;
        cin >> S;
        int w;
        cin >> w;
        int l = S.size();
        for (int i=0; w * i + 1 <= l; i++) {
                cout << S[w * i];
        }
        cout << endl;
        return 0;
}
