#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main(){
    int N, M;
    cin >> N;
    vector<string> blue(N);
    rep(i, N){
        cin >> blue.at(i);
    }

    cin >> M;
    vector<string> red(M);
    rep(i, M){
        cin >> red.at(i);
    }

    int max = 0;
    int balance;
    
    string check;
    rep(i, N){
        check = blue.at(i);
        balance = 0;

        rep(j, N){
            if (check == blue.at(j)){
                
                balance += 1;
            }
        }

        rep(j, M){
            if (check == red.at(j)){
                balance -= 1;
            }
        }

        if (max < balance)
            max = balance;
    }

    if (max > 0){
        cout << max << endl;
    }
    else
    {
        cout << "0" << endl;
    }
    
}