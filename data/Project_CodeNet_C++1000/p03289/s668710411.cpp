#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
using P = pair<int,int>;

int main(void){
    string s;
    cin >> s;
    int flag = 1;
    if(s[0] != 'A') flag = 0;

    int cnt_C = 0;
    for(int i=2; i<=s.length()-2; i++){
        if(s[i] == 'C') cnt_C++;
        else if(isupper(s[i])) flag = 0;
    }
    if(cnt_C != 1) flag = 0;

    if(isupper(s[1])) flag = 0;
    if(isupper(s[s.length()-1])) flag = 0;

    if(flag) cout << "AC" << endl;
    else cout << "WA" << endl;
    return 0;
}