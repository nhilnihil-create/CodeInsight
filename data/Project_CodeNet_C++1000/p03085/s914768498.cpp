#include<bits/stdc++.h>

using namespace std;
using ll = long long;


int main()
{
    char c; cin >> c;
    cout << (c == 'A' ? 'T' : c == 'T' ? 'A' : c == 'C' ? 'G' : 'C') << endl;
}