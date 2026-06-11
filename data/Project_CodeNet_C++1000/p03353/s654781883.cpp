
#include <iostream>
#include <cstdio>
#include <string>
#include <cmath>
#include <cctype>
#include <cstdlib>
#include <stack>
#include <queue>
#include <vector>
#include <algorithm>
#include <list>
#include <map>
#include <set>
using namespace std;

string makeSub(string s, int l, int r) {
    string t = s.substr(l, r - l + 1);
    return t;
}
int main() {
    string s;
    int k;
    cin >> s >> k;
    int n = s.size() - 1;
    set<string> p;
    map<string, int> q;
    for (int i = 0; i <= n;i++) {
        for (int j = i;j <= min(k+i-1,n);j++) {
            string t = makeSub(s, i, j);
            if (q[t] >= 1) q[t]++;
            else {
                p.insert(t);
                q[t]++;
            }
        }
    }
    set<string>::iterator it = p.begin();
    int l = 1;
    while (l < k) {
        it++;
        l++;
    }
    cout << *it << endl;
}
	