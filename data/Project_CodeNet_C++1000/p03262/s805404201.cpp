#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int INF = 1001001001;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int gcd(int a,int b) {
if (a%b == 0) return b;
else return gcd (b,a%b);

}

int main() {
int N,X;
cin >> N >> X;
vector<int> vec(N);
cin >> vec.at(0);
int mini = abs(X - vec.at(0));
for (int i = 1;i < N;i++) {
    cin >> vec.at(i);
    mini = min(mini,gcd(mini,abs(X - vec.at(i))));
}

cout << mini << endl;


return 0;
}
