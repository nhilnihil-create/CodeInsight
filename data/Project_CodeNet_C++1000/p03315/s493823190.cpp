#include <bits/stdc++.h>
 
using namespace std;

#define precise(n,k) fixed<<setprecision(k)<<n

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
 
int main() {
    
    string s;
    
    cin >> s;
    
    int n = s.size();
    
    int x = 0;
    
    for(int i = 0; i < n; ++i) {
        if(s[i] == '-') {
            x--;
        } else if(s[i] == '+'){
            x++;
        }
    }
    
    cout << x << endl;
   
    
	return 0;
}
