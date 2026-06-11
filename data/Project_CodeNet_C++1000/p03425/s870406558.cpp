#include <iostream>
#include <map>
using namespace std;
int main() {
    int n;
    cin >> n;
    map<char, long long> mp;
    for (int i=0; i<n; i++) {
        string s;
        cin >> s;
        mp[s[0]]++;
    }
    long long result = 0;
    char march[5] = {'M', 'A', 'R', 'C', 'H'};
    for (int i=0; i<3; i++) {
        for (int j=i+1; j<4; j++) {
            for (int k=j+1; k<5; k++) {
                result += mp[march[i]]*mp[march[j]]*mp[march[k]];
            }
        }
    }
    cout << result << endl;
}