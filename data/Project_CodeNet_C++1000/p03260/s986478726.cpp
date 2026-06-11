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
    cin >> a >> b;

    cout << ((a * b) % 2 == 0 ? "No\n" : "Yes\n");

    return 0;
}
