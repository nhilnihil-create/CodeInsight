#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    int c = 0;
    cin >> s;

    for(int i=0; i<s.size()-1; i++){
        if(s[i] == '0' && s[i+1] == '0'){
            s[i+1] = '1';
            c++;
        }
        if(s[i] == '1' && s[i+1] == '1'){
            s[i+1] = '0';
            c++;
        }
    }

    cout << c << endl;
    return 0;
}