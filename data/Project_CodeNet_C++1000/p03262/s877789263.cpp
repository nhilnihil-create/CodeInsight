#include <bits/stdc++.h>

using namespace std;

int gcd(int a, int b) {
    return (b ? gcd(b, a % b) : a);
}

int Solve(vector<int> a, int x) {
    int n = a.size();
    int ans = 0;
    for(int i = 0; i < n; i++) {
        ans = gcd(abs(a[i] - x), ans);
    }
    return ans;
}

int main() {
   ios::sync_with_stdio(false);
   cin.tie(0);
   int n, x;
   cin >> n >> x;
   vector<int> a(n);
   for(int i = 0; i < n; i++) {
       cin >> a[i];
   }
   cout << Solve(a, x) << endl;
}