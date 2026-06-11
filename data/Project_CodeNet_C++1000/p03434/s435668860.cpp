#include <bits/stdc++.h>
using namespace std;
 
int main() {
    int n; cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    sort(a.begin(),a.end());
    int alice=0;
    int bob= 0;
    for (int i = n-1; 0 <= i; i=i-2)
    {
        alice = alice + a[i];
    }
    for (int i = n-2; 0 <= i; i = i-2)
    {
        bob = bob + a[i];
    }
    cout << alice - bob << endl;
    
}