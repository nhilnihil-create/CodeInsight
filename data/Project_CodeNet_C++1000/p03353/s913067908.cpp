#include <iostream>
#include <string>
#include <set>

using namespace std;

int main() {
    set<string> st;
    string s; int k;    cin >> s >> k;
    int l = s.length();

    for (int i = 0; i < l; i++) {
        for (int j = 1; j <= 5; j++) {
            if (i + j - 1 < l)
                st.insert(s.substr(i, j));
        }
    }

    set<string>::iterator ite = st.begin();
    int i = 1;
    while (i++ < k)
        ite++;
    
    cout << *ite << endl;
    return 0;
}