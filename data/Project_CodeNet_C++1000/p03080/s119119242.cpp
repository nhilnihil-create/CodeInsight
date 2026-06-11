#include <bits/stdc++.h>
using namespace std;
int main(void){
    int n;
    cin >> n;
    string s;
    cin >> s;
    int countR=0, countB=0;
    
    for(int i=0;i<100;i++){
        if(s[i]=='R') countR++;
        if(s[i]=='B') countB++;
    }
    if(countR>countB){
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
    
    return 0;
}
