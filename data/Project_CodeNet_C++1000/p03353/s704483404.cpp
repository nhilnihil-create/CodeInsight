#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    string s;
    int K;
    cin >> s >> K;
    vector<string>a;
    set<string>b;

    for (int i = 0; i < s.size(); i++) {
        for (int j = 0; j <= K; j++) {
            string t = "";
            for (int k = 0; k < j; k++) {
                if (i+k < s.size()) {
                    t += s[i+k];
                }
            }
            if (t != "") {
                a.push_back(t);
            }
        }
    }
    
    sort(a.begin(), a.end());
    for (int i = 0; i < a.size(); i++) {
        b.insert(a[i]);
    }
    
    auto itr = b.begin();
    int cnt = 1;
    while (cnt < K) {
        cnt++;
        itr++;
    }
    cout << *itr << endl;
}
