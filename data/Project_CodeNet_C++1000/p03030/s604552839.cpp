#include <iostream>
#include <stdio.h>
#include <vector> 
#include <math.h> 
#include <map> 
#include <algorithm>

using namespace std;

int main(void) {
    int n; cin >> n;
    int i = 0;
    map<string, vector<int> > m;
    map<string, int > index;
    while (i < n) {
        string s;
        int p;
        cin >> s >> p;
        index[s+to_string(p)] = i + 1;
        m[s].push_back(p);
        i++;
    }
    for (auto itr = m.begin(); itr != m.end(); itr++) {
        if (itr->second.size() > 1) {
            int j = 0;
            sort(itr->second.begin(), itr->second.end(), greater<int>());
            while(j < itr->second.size()) {
                cout << index[itr->first+to_string(itr->second[j])] << endl;
                j++;
            }
        } else {
            cout << index[itr->first+to_string(itr->second[0])] << endl;
        }
    }
}
