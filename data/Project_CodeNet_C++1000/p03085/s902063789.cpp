#include <iostream>
#include <map>
using namespace std;

int main() {
    char b;
    cin >> b;

    map<char, char> mp;
    mp['A'] = 'T';
    mp['T'] = 'A';
    mp['C'] = 'G';
    mp['G'] = 'C';

    cout << mp[b] << endl;
}