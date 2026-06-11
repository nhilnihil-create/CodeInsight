#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)

void input(int &n, vector<int> &a) {
    cin >> n;
    a.resize(n);
    rep(i,n) {
        cin >> a[i];
    }
}

int div(int n) { // 整数が2で割り切れる回数
    int count = 0;
    while (n % 2 == 0) {
        n /= 2;
        count++;
    }
    return count;
}

int main() {
    int n; vector<int> a;
    input(n, a);

    int sum = 0;
    rep(i,n) { //各要素の2で割り切れる回数の総和
        sum += div(a[i]);
    }
    cout << sum << endl;
}