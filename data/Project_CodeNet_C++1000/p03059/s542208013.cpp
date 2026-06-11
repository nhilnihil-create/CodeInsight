#include <bits/stdc++.h>
using namespace std;


#define vi vector<int>
#define pb push_back
#define pii pair<int, int>
#define mp make_pair
#define ll long long


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int a, b;
    double t;

    cin >> a >> b >> t;
    t += 0.5;

    cout << b * ((int) (t / a)) << endl;


    return 0;
}
