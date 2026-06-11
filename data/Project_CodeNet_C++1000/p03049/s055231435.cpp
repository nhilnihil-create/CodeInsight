#include <bits/stdc++.h>

using namespace std;

int count_ab(const string& str) {
    int ret = 0;
    for(int i=0;i<str.length()-1;i++) {
        if(str[i] == 'A' && str[i+1] == 'B') {
            ret++;
        }
    }
    return ret;
}

int main() {
    int N; cin >> N;
    int has_AB = 0;
    int has_A  = 0;
    int has_B  = 0;
    int count = 0;
    string S;
    for(int i=0;i<N;i++) {
        cin >> S;
        count += count_ab(S);

        if(S.back() == 'A' && S.front() == 'B') {
            has_AB++;
        } else if(S.back() == 'A' && S.front() != 'B') {
            has_A++;
        } else if(S.back() != 'A' && S.front() == 'B') {
            has_B++;
        }
    }

    if(has_A + has_B == 0) {
        cout << count + max(0, has_AB - 1) << endl;
    } else {
        cout << count + has_AB + min(has_A, has_B) << endl;
    }

    return 0;
}
