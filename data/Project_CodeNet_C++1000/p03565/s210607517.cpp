#include<iostream>
#include<vector>

using namespace std;

bool check(string s, string t, int top){
    for (int i = 0; i < t.length(); i++){
        if((s[top + i] == t[i]) || (s[top + i] == '?')){
            continue;
        }else{
            return false;
        }
    }
    return true;
}
int main(){
    string S, T;
    int top = -1;

    cin >> S;
    cin >> T;

    for (int i = 0; i < S.length() - T.length() + 1; i++){
        if(check(S, T, i)){
            top = i;
        }
    }

    if (top == -1)
    {
        cout << "UNRESTORABLE" << endl;
        return 0;
    }
    
    for (int i = 0; i < T.length(); i++){
        S[top + i] = T[i];
    }

    for (int i = 0; i < S.length(); i++){
        if(S[i] == '?'){
            S[i] = 'a';
        }
    }

    cout << S << endl;
    return 0;
}