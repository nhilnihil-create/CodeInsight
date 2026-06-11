#include <bits/stdc++.h>
using namespace std;

string S2, T;

int main() {
    cin >> S2;
    cin >> T;
    int l_S = S2.size(), l_T = T.size();
    vector<string> changed_sentences(0);
    
    for (int i = 0; i <= l_S - l_T; i++) {
        bool is_match = true;
        for (int j = 0; j < l_T; j++) {
            if(S2.at(i + j) != '?' && S2.at(i + j) != T.at(j)) {
                is_match = false;
                break;
            }
        }

        
        if (is_match) {
            string changed = S2;

            for (int k = 0; k < l_S; k++) {
                if (changed.at(k) == '?') {
                    changed.at(k) = 'a';
                }
            }
            for (int l = 0; l < l_T; l++) {
                changed.at(i + l) = T.at(l);
            }
            changed_sentences.push_back(changed);
        }
    }

    if (changed_sentences.size() == 0) {
        cout << "UNRESTORABLE" << endl;
    }
    else {
        cout << *min_element(changed_sentences.begin(), changed_sentences.end()) << endl;
    }
}