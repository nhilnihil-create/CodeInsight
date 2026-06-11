#include<bits/stdc++.h>
using namespace std;

int main()
{
    string s;

    cin >> s;

    int len = s.length();
    int cnt = 0;
    for(int i = 1; i < len; i++){
        if(s[i] == '1' && s[i - 1] == '1'){
            s[i] = '0';
            cnt++;
        }
        if(s[i] == '0' && s[i - 1] == '0'){
            s[i] = '1';
            cnt++;
        }
    }
    cout << cnt << endl;
    return 0;

}
