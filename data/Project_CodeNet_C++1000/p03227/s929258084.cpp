#include <bits/stdc++.h>
using namespace std;
int main () {
    
    string s;
    cin >> s;
    if (s.size() == 2)  
        cout << s << endl;
    else    for (int i = s.size()-1; i >= 0; --i)   cout << s[i];
    
    return 0;
}