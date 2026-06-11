#include <bits/stdc++.h>
using namespace std;
#define PI 3.141592653589793
#define MOD 1000000007
typedef long long ll;
typedef long double ld;


int main() {
    string str;
    cin >> str;

    if (str == "zyxwvutsrqponmlkjihgfedcba") {
        cout << -1;
    } else if (str.size() == 26) {
        string tmp = str;
        next_permutation(str.begin(), str.end());

        string kekka = "";
        for (int i = 0; i < int(str.size()); i++) {
            kekka += str.at(i);
            if (str.at(i) > tmp.at(i)) break;
        }

        cout << kekka;
    } else {
        map<char,int> mp;
        for (int i = 0; i < int(str.size()); i++) mp[str[i]]++;

        for (int i = 0; i < 26; i++) {
            if (mp['a' + i] == 0) {
                str += 'a' + i;
                cout << str << endl;
                return 0;
            }
        }
    }

}