#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; i++)
typedef long long int ll;
template<typename T> T changeMax(T& a, T b){if(a < b)a = b;return 0;}

int main()
{
    int a, b;
    cin >> a >> b;
    cout << (a*b)-a-b+1 << endl;
    system("pause");
}