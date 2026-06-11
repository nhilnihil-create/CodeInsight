#include <bits/stdc++.h>

using namespace std;

int main(){
    string S,T;

    cin >> S >> T;

    bool flag = true;

    map<char, char> a, b;

    for(int i = 0; i < S.size(); i++){
        char s = S[i], t = T[i];
        if(a.count(s)){
            if(a[s] != t){
                flag = false;
            }
        }
        if(b.count(t)){
            if(b[t] != s){
                flag = false;
            }
        }

        a[s] = t;
        b[t] = s;
    }

    if(flag) cout << "Yes" << endl;
    else cout << "No" << endl;

}