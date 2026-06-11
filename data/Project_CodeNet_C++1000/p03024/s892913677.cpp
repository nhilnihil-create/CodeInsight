#include <bits/stdc++.h>
using namespace std;
 
int main(){
    string S;
    cin >> S;

    int N = S.length();
    int cnt_o = 0;
    int cnt_x = 0;

    for (int i = 0; i < N; i++){
        if(S[i] == 'x'){
            cnt_x++;
        }
        else {
            cnt_o++;
        }
    }

    if (cnt_x > 7){
        cout << "NO" << endl;
    }
    else {
        cout << "YES" << endl;
    }
}