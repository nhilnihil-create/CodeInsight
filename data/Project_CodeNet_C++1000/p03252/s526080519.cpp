#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define rep(N) for (int i = 0; i < N; i++)

int count_char(string S, char c){
    int count = 0;
    int pos = S.find(c);

    while (pos != string::npos){
        count++;
        pos = S.find(c, pos + 1);
    }

    return count;
}

int main(){
    string S, T;
    cin >> S >> T;
    int i = 0;
    vector<int> S_char_counts('z'-'a' + 1);
    vector<int> T_char_counts('z'-'a' + 1);
    bool can_match = true;
    for (char c = 'a'; c <= 'z'; c++){
        S_char_counts[i] = count_char(S, c);
        T_char_counts[i] = count_char(T, c);
        i++;
    }
    sort(S_char_counts.begin(), S_char_counts.end());
    sort(T_char_counts.begin(), T_char_counts.end());
    for (i = 0; i < 'z' - 'a' + 1; i++){
        if (S_char_counts[i] == T_char_counts[i]){
            continue;
        }else{
            can_match = false;
            break;
        }
    }
    if (can_match == true) cout << "Yes" << endl;
    else cout << "No" << endl;
}
