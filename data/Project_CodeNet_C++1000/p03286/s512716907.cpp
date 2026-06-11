#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    vector<int> res;
    if(n == 0) {
        cout << "0" << endl;
        return 0;
    }
    while (n)
    {
        if(n % (-2) == 0) {
            res.push_back(0);
            n /= (-2);
        }
        else if(n % (-2) == -1) {
            res.push_back(1);
            n = n / (-2) + 1;
        }
        else {
            res.push_back(1);
            n = n / (-2);
        }
    }
    reverse(res.begin(), res.end());
    for (auto r : res)
    {
        cout << r;
    }
    cout << endl;
	return 0;
}

