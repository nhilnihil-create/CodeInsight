#include <bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin >> s;
    
    int mindif = 999;
    for (int i = 0; i < s.size() - 2; i++) {
        string buf = s.substr(i,3);
        int bufnum = stoi(buf);
        int bufdif = abs(753 - bufnum);
        mindif = min(mindif,bufdif);
    }
    
    cout << mindif << endl;
}
