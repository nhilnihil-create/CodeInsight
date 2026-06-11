#include <bits/stdc++.h>
using namespace std;

int main(void) {
    int N;
    int tmp;
    cin >> N;

    vector<int> c(N-1);
    vector<int> s(N-1);
    vector<int> f(N-1);
    vector<int> curtime(N-1);
    for(int i=0;i<(N-1);i++) {
        cin >> c[i] >> s[i] >> f[i];
        curtime[i] = s[i];
    }

    for(int i=0;i<c.size();i++) {
        for(int j=i;j<c.size();j++) {
            if(s[j] >= curtime[i]) {
                curtime[i] = s[j];
            } else {
                // これで通ったらおかしい。その後は、って書いてあるし
                if(curtime[i]%f[j])curtime[i] += f[j]-(curtime[i]%f[j]);
//                tmp = curtime[i] - s[j];
//                if(tmp%f[j]) {
//                    curtime[j] += f[j]-(tmp%f[j]);
//                } else {
//                    // 来ている
//                }
            }

            curtime[i] += c[j];
        }
    }

    for(int i=0;i<(N-1);i++) {
        cout << curtime[i] << endl;
    }
    cout << "0\n";
    return 0;
}
