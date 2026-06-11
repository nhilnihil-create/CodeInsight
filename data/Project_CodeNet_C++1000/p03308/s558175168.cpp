#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;


int main() {
    int N;
    cin >> N;

    vector<int> v(N);
    rep(i, N) { cin >>v.at(i); }

    sort(v.begin(), v.end());
    
    cout << abs(v.at(N - 1) - v.at(0)) << endl;

}
