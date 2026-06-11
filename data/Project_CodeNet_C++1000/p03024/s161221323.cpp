#include<iostream>

using namespace std;

string S;
int main () {
    cin >> S ;
    int l = S.size();
    int cnt = 0;
    for(int i=0; i<l; i++) if( S[i] == 'o') cnt++;
    if( 15 - l >= 8 - cnt) cout << "YES" << endl;
    else cout << "NO" << endl;
    return 0;
}