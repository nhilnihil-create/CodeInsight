#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(){
    string S;
    cin >> S;
    bool f = true;
    int l = S.length();

    if (l < 5 || l >= 10){
        f = false;
    }
    
    vector <char> s(9);
    for (int i = 0; i < min(9, l); i++){
        s[i] = S[i];
    }

    if (s[0] != 'A'){
        for (int i = 8; i >= 1; i--){
            s[i] = s[i - 1];
        }
        s[0] = 'A';
    }
    
    if (s[4] != 'A'){
        for (int i = 8; i >= 5; i--){
            s[i] = s[i - 1];
        }
        s[4] = 'A';
    }

    if (s[6] != 'A'){
        for (int i = 8; i >= 7; i--){
            s[i] = s[i - 1];
        }
        s[6] = 'A';
    }

    if (s[8] != 'A'){
        s[8] = 'A';
    }
    
    string K = "AKIHABARA";

    for (int i = 0; i < 9; i++){
        if (s[i] != K[i]){
            f = false;
            break;
        }
    }
    
    if (f == true){
        cout << "YES" << endl;
    }else{
        cout << "NO" << endl;
    }

    return 0;
}