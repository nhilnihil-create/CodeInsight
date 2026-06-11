#include<bits/stdc++.h>
using namespace std;
template <typename T> using vec = vector<T>;

int main()
{
    int n,a,b;
    cin >> n >> a >> b;
    cout << (abs(a-b)%2==0 ? "Alice" : "Borys") << endl;
}