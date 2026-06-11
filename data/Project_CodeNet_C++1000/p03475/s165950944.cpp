#include <bits/stdc++.h>
using namespace std;

int main() {
    //
    int num;

    cin >> num;
    vector<int> c(num, 0);
    vector<int> s(num, 0);
    vector<int> f(num, 0);
    vector<long long> ans(num, 0);
    for (int i = 0; i < num - 1; i++) cin >> c.at(i) >> s.at(i) >> f.at(i);

    for (int i = 0; i < num; i++) {
        int t = 0;
        for (int j = i; j < num - 1; j++) {
            if (t < s.at(j))
                t = s.at(j);
            else if (t % f.at(j) == 0)
                ;
            else
                t += f.at(j) - t % f.at(j);
            t += c.at(j);
        }
        cout << t << endl;
    }

    //
}
