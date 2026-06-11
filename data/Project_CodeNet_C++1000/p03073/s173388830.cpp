#include <bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin >> s;
    int c1 = 0, c2 = 0; //c1は0スタート、c2は1スタート
    for (int i = 0, lim = s.size(); i < lim; i++)
    {
        if (i % 2 == 0) {
            s[i] == '0' ? c2++ : c1++;
        }
        else {
            s[i] == '1' ? c2++ : c1++;
        }
    }
    cout << min(c1, c2) << endl;
}