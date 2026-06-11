#include<iostream>
#include<string>
#include<map>
using namespace std;

int main() {
    string S;
    cin >> S;

    string before = "ATCG";
    string after = "TAGC";
    map<char, char> m;

    for(int i=0; i<before.size(); i++) {
        m[before[i]] = after[i];
    }
    char ans = m[S[0]];

    cout << ans << endl;
}