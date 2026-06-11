#include <bits/stdc++.h>
using namespace std;
using ll = long long; // ll は long long　と同じとする。
int main () {
    string S;
    cin >> S;
    int win = 0;
    int lose = 0;
    for(int i = 0; i < S.size(); i++){
        if(S.at(i) == 'o'){
            win++;
        }
        else{
            lose++;
        }
    }
    if(win >= 7 || lose < 8){
        cout << "YES" << endl;
    }
    else{
        cout << "NO" << endl;
    }
}
