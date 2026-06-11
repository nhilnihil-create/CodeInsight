#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    cin >> s;
    long long n = s.size(), sum = 0, i=0, j=1;

    for(; i<n; i++){
        if(s[i] == 'W'){
            sum += (i-j)+1;
            j++;
        }
    }

    cout << sum << endl;
    return 0;
}