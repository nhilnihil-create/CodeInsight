#include <iostream>
#include <string>
#include <map>
#include <vector>
using namespace std;

int main() {

    string s, t;

    cin >> s;
    cin >> t;

    int n = s.size();

    map<char, int> usedMapS;
    vector<int> sNum(n);
    int count = 0;

    for(int i = 0; i < n; ++i) {

        if(usedMapS.find(s[i]) == usedMapS.end()) {
            usedMapS[s[i]] = count++;
        }
        sNum[i] = usedMapS[s[i]];

    }

    usedMapS.clear();

    vector<int> tNum(n);
    count = 0;

    for(int i = 0; i < n; ++i) {

        if(usedMapS.find(t[i]) == usedMapS.end())
            usedMapS[t[i]] = count++;
        
        tNum[i] = usedMapS[t[i]];
    }

    if(tNum == sNum)
        cout << "Yes" << endl;
    else 
        cout << "No" << endl;

    return 0;

}