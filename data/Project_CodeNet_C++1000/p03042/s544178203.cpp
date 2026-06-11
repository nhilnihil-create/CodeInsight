/*
      author  : nishi5451
      created : 15.08.2020 00:36:19
*/

#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<n; i++)
typedef long long ll;


int main(){
    string s;
    cin >> s;
    int l = 10*(s[0]-'0')+(s[1]-'0');
    int r = 10*(s[2]-'0')+(s[3]-'0');
    if(1<=r && r<=12 && 1<=l && l<=12){
        cout << "AMBIGUOUS" << endl;
    }
    else if(1<=l && l<=12){
        cout << "MMYY" << endl;
    }
    else if(1<=r && r<=12){
        cout << "YYMM" << endl;
    }
    else {
        cout << "NA" << endl;
    }
    return 0;
}