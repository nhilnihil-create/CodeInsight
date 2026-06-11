#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
  string S;
  cin >> S;
    if(S.substr(S.size()-7,7)=="keyence") cout << "YES" << endl;
    else if(S.substr(0,1)=="k" && S.substr(S.size()-6,6)=="eyence") cout << "YES" << endl;
    else if(S.substr(0,2)=="ke" && S.substr(S.size()-5,5)=="yence") cout << "YES" << endl;
    else if(S.substr(0,3)=="key" && S.substr(S.size()-4,4)=="ence") cout << "YES" << endl;
    else if(S.substr(0,4)=="keye" && S.substr(S.size()-3,3)=="nce") cout << "YES" << endl;
    else if(S.substr(0,5)=="keyen" && S.substr(S.size()-2,2)=="ce") cout << "YES" << endl;
    else if(S.substr(0,6)=="keyenc" && S.substr(S.size()-1,1)=="e") cout << "YES" << endl;
    else if(S.substr(0,7)=="keyence") cout << "YES" << endl;
    else cout << "NO" << endl;
}