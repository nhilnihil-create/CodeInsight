#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    int k,ans=0;
    cin >> s;
    k = s.length();
    for (int i=0; i<k; i++){
        if (s.at(i) == 'o') ans ++;
    }
    if (15-k+ans > 7){
        cout << "YES" << endl;
    }
    else{
        cout << "NO" << endl;
    }
}