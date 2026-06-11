#include <bits/stdc++.h>

using namespace std;

int main (void) {
    string S, T;
    cin >> S >> T;

    /* 変換対象の値をそれぞれ入れる */
    vector<int> s_char_array(26, -1);
    vector<int> t_char_array(26, -1);

    int s_char, t_char;
    for ( int i=0; i<(int)S.size(); i++ ) {
        s_char = S.at(i) - 'a';
        t_char = T.at(i) - 'a';

        /* もしすでに変換対象が存在したら変換できない */
        if ( s_char_array[s_char] != -1 ||
             t_char_array[t_char] != -1 ) {
            if ( s_char_array[s_char] != t_char &&
                 t_char_array[t_char] != s_char ) {
                cout << "No" << endl;
                return 0;
            }
        }
        s_char_array[s_char] = t_char;
        t_char_array[t_char] = s_char;
    }
    cout << "Yes" << endl;
    return 0;
}
