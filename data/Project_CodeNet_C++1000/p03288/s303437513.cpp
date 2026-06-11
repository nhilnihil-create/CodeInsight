#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; i++)
typedef long long int ll;
template<typename T> T changeMax(T& a, T b){if(a < b)a = b;return 0;}

int main()
{
    int n;
    cin >> n;
    if(n < 1200)cout << "ABC" << endl;
    else if(n < 2800) cout << "ARC" << endl;
    else cout << "AGC" << endl;
    system("pause");
}