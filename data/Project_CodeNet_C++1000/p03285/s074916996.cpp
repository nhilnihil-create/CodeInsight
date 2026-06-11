#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, fou, syotyou, res;
    bool flag = false;
    cin >> N;

    fou = N/4;
    syotyou = N/7;

    for (int i = 0; i <= fou; i++){
        for (int j = 0; j <= syotyou; j++){
            if (i*4 + j*7 == N){
                flag = true;
                break;
            }
        }
    }

    if (flag == true){
        cout << "Yes" << endl;
    }
    else{
        cout << "No" << endl;
    }
}