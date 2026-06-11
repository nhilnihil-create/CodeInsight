#include <bits/stdc++.h>
using namespace std;
 
 
int main() {
    string S;
    cin >> S;
    char tuki=S.at(6);
    if(S.at(5)=='0'&&(tuki=='1'||tuki=='2'||tuki=='3'||tuki=='4')) cout << "Heisei" << endl;
    else cout << "TBD" << endl;
}