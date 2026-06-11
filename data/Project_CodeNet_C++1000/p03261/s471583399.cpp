#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>
#include <vector>
using namespace std;



int main(){
    int n;
    cin >> n;
    
    vector<string> words;
    
    string s;
    string last_word;
    for (int i = 0; i < n; i++) {
        cin >> s;
        if (i == 0) {
            words.push_back(s);
            continue;
        }
        for (auto j: words) {
            if (j == s) {
                cout << "No" << endl;
                return 0;
            }
        }
        
        last_word = words.back();
        if ( last_word[last_word.length() - 1] != s[0]) {
            cout << "No" << endl;
            return 0;
        }
        
        words.push_back(s);
    }
    cout << "Yes" << endl;
    
    return 0;
}