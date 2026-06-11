#include<bits/stdc++.h>
#include<string>

using namespace std;

//入力
int N = 0, A = 0 ;

void solve(){
    int sum = 0;
    sum = N % 500;

    if (sum <= A){
        cout << "Yes";
    }

    else {
        cout << "No";
    }

}

int main() {

    cin >> N;
    cin >> A;

    solve();
}