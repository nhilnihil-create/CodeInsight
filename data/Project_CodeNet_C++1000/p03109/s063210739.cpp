#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (n); i++)
typedef long long ll;
using namespace std;

int main(){
    string s;
    cin >> s;
//    int y = stoi(s.substr(0,4));
    int m = stoi(s.substr(5,2));
//    int d = stoi(s.substr(8,2));

    if(m < 5) cout << "Heisei" << endl;
    else cout << "TBD" << endl;
}
