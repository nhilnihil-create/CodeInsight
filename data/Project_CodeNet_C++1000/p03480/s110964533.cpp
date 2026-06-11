#include <bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin >> s;
    int i, m = (int)s.length(), n = m;
    for(i=0; i<n-1; i++){
        if(s[i] != s[i+1]){
            m = min(m, max(i+1, n-i-1));
        }
    }
    cout << m;
    return 0;
}