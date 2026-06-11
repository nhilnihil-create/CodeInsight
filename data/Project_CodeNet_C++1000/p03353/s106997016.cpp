#include<iostream>
#include<string>
#include<set>
#include<vector>
#include<algorithm>

using namespace std;

int main() {
    string s; cin >> s;
    int k; cin >> k;
    set<string> substr;
    int limit = min(k, (int)s.size());
    for(int i=1; i<=limit; ++i) {
        // O(k)
        for(int j=0; j<=s.length()-i; ++j) {
            // O(N)
            string tmp = "";
            for(int k=0; k<=i-1; k++) {
                tmp += s[j+k];
            }
            substr.insert(tmp);
        }
        
    }
    vector<string> substrs;
    for(auto str:substr) {
        substrs.push_back(str);
    }

    cout << substrs[k-1] << endl;
    return 0;
}