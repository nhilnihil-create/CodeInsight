#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    int a, b, c ,d;
    cin >> a >> b >> c >> d;
    a+=b, c+=d;
    if(a>c)cout << "Left";
    else if(a<c)cout << "Right";
    else cout << "Balanced";
}

