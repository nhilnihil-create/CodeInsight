#include<bits/stdc++.h>
#include<string>

using namespace std;

//入力
char N [9999];

void solve(){
    if ((N[0] == N[1] && N[1]  == N[2]) || (N[1] == N[2] && N[2] == N[3])) {
        cout << "Yes"<< endl;
    }

    else {
        cout << "No" << endl;
    }
}

int main() {

    cin >> N;

    solve();
}