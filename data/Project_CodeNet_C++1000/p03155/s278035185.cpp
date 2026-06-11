#include<bits/stdc++.h>
using namespace std;
template <typename T> using vec = vector<T>;

int main()
{
    int n,h,w;
    cin >> n >> h >> w;
    cout << max(0,n-h+1)*max(0,n-w+1) << endl;
}