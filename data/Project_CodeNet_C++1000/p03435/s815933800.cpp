#include <bits/stdc++.h> 
using namespace std; 
typedef long long int ll;
typedef unsigned long long int ull;
const long long int m=pow(10,9)+7;

int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int A, B, C, D, E, F, G, H, I;
    cin >> A >> B >> C >> D >> E >> F >> G >> H >> I;
    if (A - D == B - E &&
    B - E == C - F &&
    D - G == E - H &&
    E - H == F - I &&
    A - B == D - E &&
    D - E == G - H &&
    B - C == E - F &&
    E - F == H - I) {
        cout << "Yes" << endl;
    }
    else cout << "No" << endl;
    return 0;
}