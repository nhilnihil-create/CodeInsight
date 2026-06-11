#include <bits/stdc++.h>
using namespace std;

int main() {
    int N; // あられ数
    int count = 0;
    string A = "PWGY";
    cin >> N;

    for (int i = 0; i < N; i++) {
        string S; // あられ種類
        cin >> S;

        for(int j = 0; j < (int)(A.length()); j++ ) {
            if (A[j] == *S.c_str()) {
                count++;
                A[j] = ' ';
                break;
            }
        }

        if (count == 4) {
            break;
        }
    }
    
    if (count == 3) {
        cout << "Three" << endl;
    }
    else if (count == 4){
        cout << "Four" << endl;
    }
}