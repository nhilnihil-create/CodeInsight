#include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
#include <utility>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define _GLIBCXX_DEBUG
using namespace std;
typedef long long ll;

int main(){
    int n; cin >> n;
    vector<int> l(n);
    rep(i, n) {
        cin >> l[i];
    }
    sort(l.begin(),l.end());
    int sum = 0;
    for (int i = 0; i < n - 1; i++) {
        sum += l[i];
    }

    if(l[n -1] < sum) {
        cout << "Yes" << endl;
    }
    else cout << "No" << endl;
}
   