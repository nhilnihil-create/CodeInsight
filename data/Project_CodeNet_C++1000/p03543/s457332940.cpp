#include <bits/stdc++.h>
#define rep(i,n) for(ll i=0;i<(n);i++)
#define all(x) (x).begin(), (x).end()
using ll = long long;
using namespace std;
template <typename T>
using vec = std::vector<T>;

int main() {
    string N;
    cin >> N;
    bool A = N[0]==N[1]&&N[0] == N[2];
    bool B = N[1]==N[2]&&N[1] == N[3];
    cout << ((A||B)?"Yes":"No") << endl;
}