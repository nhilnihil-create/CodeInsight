/*
      author : nishi5451
      created: 11.08.2020 21:23:02
*/

#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<n; i++)
typedef long long ll;


int main(){
    string s;
    cin >> s;
    int month = (s[5]-'0')*10 + (s[6]-'0');
    int date = (s[8]-'0')*10 + (s[9]-'0');
    if(month>=5) cout << "TBD" << endl;
    else if(month==4 && date>30) cout << "TBD" << endl;
    else   cout << "Heisei" << endl;
    return 0;
}