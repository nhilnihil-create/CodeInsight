#include <bits/stdc++.h>
using namespace std;

int main(void) {
    string S;
    int e;
    int cnt = 0;
    bool judge = true;
    cin >> S;
    e = S.size() -1;
    if(S[0] != 'A') judge = false;
    if(S[1] < 'a' || S[1] > 'z') judge = false;
    if(S[e] < 'a' || S[e] > 'z') judge = false;
    for(int i=2;i<e;i++) {
       if(S[i] < 'a' || S[i] > 'z'){
            cnt++;
            if(S[i] != 'C') judge = false;
        }
    }

    if(cnt == 1 && judge) {
        cout << "AC\n";   
    } else {
        cout << "WA\n";   
    }
    return 0;
}
