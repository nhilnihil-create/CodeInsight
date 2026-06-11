#include <bits/stdc++.h>
using namespace std;

int main(void){
    string s, t;
    cin >> s >> t;
    
     
    
    sort(s.begin(), s.end());
    sort(t.begin(), t.end());
    reverse(t.begin(), t.end());
    
    bool flag = true;
    for (int i=0; i<min(s.size(), t.size()); i++) {
        if (s.at(i) != t.at(i)) flag = false;
    }
    if (s < t || (flag && s.size() < t.size())) cout << "Yes" << endl;
    else cout << "No" << endl;
    
    
    
    
}

