#include <bits/stdc++.h>
//#include <atcoder/all>
//using namespace atcoder;
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); i++)
typedef pair<int,int> P;
typedef long long ll;



int main() {
    string s;
    cin >> s;
    
    string s1 = {s[0],s[1]}, s2 = {s[2],s[3]};
    int x = stoi(s1), y = stoi(s2);
    
    if(x >= 1 && x <= 12) {
        if(y >= 1 && y <= 12)
            cout << "AMBIGUOUS" << endl;
        else
            cout << "MMYY" << endl;
    }
    else {
        if(y >= 1 && y <= 12)
            cout << "YYMM" << endl;
        else
            cout << "NA" << endl;
    }
    
    
    
    return 0;
}
