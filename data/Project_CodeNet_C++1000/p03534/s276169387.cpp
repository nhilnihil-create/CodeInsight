#include <iostream>

using namespace std;

int main(){
    string S;
    cin >> S;
    int a = 0, b = 0, c = 0;
    for(int i = 0; i < S.size(); i++){
        if(S[i] == 'a') a++;
        if(S[i] == 'b') b++;
        if(S[i] == 'c') c++;
    }
    if(max(a, max(b, c)) - min(a, min(b, c)) >= 2) cout << "NO" << endl;
    else cout << "YES" << endl;
}