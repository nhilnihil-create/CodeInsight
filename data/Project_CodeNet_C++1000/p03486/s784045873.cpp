#include<iostream>
//#include<string>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    string s, t;
    cin >> s >> t;
    vector<char> v_s;
    vector<char> v_t;
    
    int s_len = (int)s.length();
    int t_len = (int)t.length();

    for (int i=0; i<s_len; i++) {
        char c = s[i];
        v_s.push_back(c);
    }
    for (int i=0; i<t_len; i++) {
        char c = t[i];
        v_t.push_back(c);
    }
    sort(v_s.begin(), v_s.end());
    sort(v_t.begin(), v_t.end(), greater<char>());
    
    if (s < t) {
        cout << "Yes";
    }
    else if (t < s) {
        if (v_s < v_t) {
            cout << "Yes";
        }
        else {
            cout << "No";   
        }
    }
    else {
        cout << "No";
    }

/*
    cout << endl << endl;
    
    for (int i=0; i<s_len; i++) {
        cout << v_s[i];
    }
    
    cout << endl;
    
    for (int i=0; i<t_len; i++) {
        cout << v_t[i];
    }
*/
}