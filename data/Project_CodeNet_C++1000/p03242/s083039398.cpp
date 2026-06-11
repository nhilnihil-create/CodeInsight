#include <bits/stdc++.h>
 
using namespace std;

typedef long long ll;

int main() {
	cin.tie(0);
    ios::sync_with_stdio(false);

    string n;
    cin >> n;

    for(int i = 0; i < n.length(); i++) {
        if(n[i] == '1')
            n[i] = '9';
        else if(n[i] == '9')
            n[i] = '1';
    }

    cout << n << endl;
}