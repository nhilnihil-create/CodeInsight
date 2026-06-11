#include <bits/stdc++.h>
using namespace std;

int main() {
    //
    long long num;
    long long kekka = 1;
    long long waru = 1000000007;
    vector<int> vec(26, 0);
    string str;

    cin >> num >> str;

    for (int i = 0; i < str.size(); i++){
        vec.at(str.at(i) - 'a')++;
    }

    for (int i = 0; i < 26; i++){
        kekka *= vec.at(i)+1;
        kekka %= waru;
    }

    cout << kekka - 1;

    //
}
