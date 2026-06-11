#include <bits/stdc++.h>
using namespace std;

int main() 
{
    string str1, str2;
    cin >> str1 >> str2;
    
    string rev1=str1, rev2=str2;
    reverse(rev1.begin(), rev1.end());
    reverse(rev2.begin(), rev2.end());
    
    if (str1 == rev2 && str2 == rev1) {
        cout << "YES" << endl;
    }else{
        cout << "NO" << endl;
    }
}