#include <bits/stdc++.h>
using namespace std;

int main() {
    
    int a, b, c;
    cin >> a >> b >> c;
    
    int mx = max(max(a, b), c);
    int mi = min(min(a, b), c);
    
    //cout << mx << endl;
    
    
    cout << mx - mi << endl;
    
    
	return 0;
}