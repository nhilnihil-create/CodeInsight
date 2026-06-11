#include <bits/stdc++.h>
using namespace std;

int main(){
    string S;
    cin >> S;
    int result = 0 ;
    for(int i=0; i < S.length(); i++){
        if (S[i] == '+'){
            result++;
        }
        else if(S[i] == '-'){
            result--;
        }
    }
    cout << result << endl;
}