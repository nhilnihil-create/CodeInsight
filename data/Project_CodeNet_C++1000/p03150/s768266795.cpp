#include <bits/stdc++.h>
using namespace std;

int main() {
    string s; cin >>s;
    string ret = "NO";

    if (s[0]=='k'
     && s[1]=='e'
     && s[2]=='y'
     && s[3]=='e'
     && s[4]=='n'
     && s[5]=='c'
     && s[6]=='e'
    ) ret = "YES";

    int size = s.size();
    if (s[size-7]=='k'
     && s[size-6]=='e'
     && s[size-5]=='y'
     && s[size-4]=='e'
     && s[size-3]=='n'
     && s[size-2]=='c'
     && s[size-1]=='e'
    ) ret = "YES";

    if (s[0]=='k' && s[size-1]=='e') {
        string key = "keyence";
        int f = 0;
        while (s[f]==key[f]){f++;}
        int b = 0;
        while (s[s.size()-b]==key[7-b]){b++;}
        if (f+b > 7) ret ="YES";
    }

    cout << ret << endl;
    return 0;
}