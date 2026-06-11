#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)
#define all(x) (x).begin(), (x).end()
using ll = long long;
using namespace std;
template <typename T>
using vec = std::vector<T>;

int main() {
    int A,B,C,D;
    cin >> A >> B >> C >> D;
    cout << min(A,B) + min(C,D) << endl;
    
}
