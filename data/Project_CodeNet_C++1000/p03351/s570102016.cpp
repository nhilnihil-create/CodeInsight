#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)
#define all(x) (x).begin(), (x).end()
using ll = long long;
using namespace std;
template <typename T>
using vec = std::vector<T>;

int main() {
    int a,b,c,d;
    cin >> a >> b >> c >> d;
    if((abs(a-b)<=d&&abs(c-b)<=d)||abs(c-a)<=d){
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
}