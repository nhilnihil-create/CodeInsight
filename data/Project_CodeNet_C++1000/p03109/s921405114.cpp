#include <bits/stdc++.h>
using namespace std;
int main(){
    string S;
    cin >> S;
    if((S[0]-'0')*1000+(S[1]-'0')*100+(S[2]-'0')*10+(S[3]-'0')<2019)cout << "Heisei" << endl;
    else if((S[0]-'0')*1000+(S[1]-'0')*100+(S[2]-'0')*10+(S[3]-'0')==2019 && (S[5]-'0')*10+(S[6]-'0')<5)cout << "Heisei" << endl;
    else cout << "TBD" << endl;
}