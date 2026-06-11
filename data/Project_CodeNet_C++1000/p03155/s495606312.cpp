#include <bits/stdc++.h>
#include<iomanip>
#define ll long long
#define pb push_back
#define mp make_pair
#define MOD 1000000007
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n,h,w;
    cin >> n >> h >> w;
    cout << (n-h+1)*(n-w+1) << "\n";
    
    return 0;
}

