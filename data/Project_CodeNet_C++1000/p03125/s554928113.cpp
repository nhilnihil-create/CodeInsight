#include <bits/stdc++.h>
#define plskz ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define ll long long
using namespace std;

int main() {
    plskz   
    int a, b;
    cin >> a >> b;
    cout << (b%a ? b-a : a+b);
}