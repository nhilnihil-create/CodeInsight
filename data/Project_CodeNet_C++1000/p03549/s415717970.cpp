#include <bits/stdc++.h>
#include <iostream>
#include<math.h>
using namespace std;
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
int main()
{
    int N, M;
    cin >> N >> M;
    int kobetsu = (1900 * M) + (100 * (N - M));
    cout << pow(2, M) * kobetsu << endl;
    return 0;
}