#include <bits/stdc++.h>
using namespace std;

int main() {

    int N;
    cin >> N;
    int L[101];
    int Max = 0, goukei = 0;
    for (int i = 0; i < N; i++) {
        cin >> L[i];
        Max = max(Max, L[i]);
        goukei += L[i];
    }
    if(Max * 2 < goukei){
        cout << "Yes" << endl;
    }
    else {
        cout << "No" << endl;
    }
    return 0;
}