#include <bits/stdc++.h>
    
using namespace std;
typedef long long ll;
    
int main()
{
    int a, b;
    cin >> a >> b;

    int count = a;
    if (a > b) { count--; }
    cout << count;
    
    return 0;
}