#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    int a;
    cin >> a;
    if(a%2==0)cout << a*a/4;
    else       cout << a/2*(a+1)/2;
}