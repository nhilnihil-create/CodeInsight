#include <bits/stdc++.h>
using namespace std;

int main(void) {
    int N;
    bool rule = true;
    cin >> N;
    vector<string> W(N);
    cin >> W[0];
    for(int i=1;i<N;i++) {
        cin >> W[i];
        if(W[i-1][W[i-1].size()-1] != W[i][0]){
//printf("i:%d c:%c\n", i, W[i][0]);
            rule = false;
        }
        for(int j=0;j<i;j++) {
            if(W[j] == W[i]) {
//printf("i:%d bef:%s\n", i, &W[i][0]);
                rule = false;
            }
        }
    }

    if(rule) {
        cout << "Yes\n";
    } else {
        cout << "No\n";
    }

    return 0;
}
