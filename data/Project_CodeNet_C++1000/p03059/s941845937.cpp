#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<int>v;
int main()
{
    int a,b,t;
    cin >> a >> b >> t;
    double T = t + 0.5;
    int A =  T / a;
    int Output =  A * b;
    cout << Output;
    return 0;
}
