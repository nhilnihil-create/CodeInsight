#include <bits/stdc++.h>
using namespace std;
 
int main() {
    string S, N;
    cin >> S >> N;
    int x=0;
    while (x<S.length()){
        string A;
        A+=S.at(S.length()-1);
        A+=S.substr(0, S.length()-1);
        if (S==N){
            cout << "Yes" << endl;
            return 0;
        }
        S=A;
        x++;
    }
    cout << "No" << endl;
}