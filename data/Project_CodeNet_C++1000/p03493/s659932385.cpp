#include <bits/stdc++.h> 
using namespace std; 
#define io ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define rep(i,n) for (int i = 0; i < (n); ++i)

int main(void) {
    io;
    int a;
    cin >> a;
    int count = 0;
    if (a &1) count++;
    if (a & 2) count++;
    if (a & 4) count++;
    cout << count << endl;
    return 0;
}

