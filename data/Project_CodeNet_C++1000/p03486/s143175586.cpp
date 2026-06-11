#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;

int main() {
  	string A, B;
    cin >> A >> B;
    
    sort (A.begin(),A.end());
    sort (B.begin(),B.end());
    reverse (B.begin(),B.end());
    
    if (A<B) cout << "Yes" << endl;
    else cout << "No" << endl;
}
