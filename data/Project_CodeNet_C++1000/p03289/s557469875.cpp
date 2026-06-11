#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;
typedef long long ll;
#define rep(i,n) for (int i = 0; i < int(n);i++)

int main(){
    string s;
    cin >> s;
    bool can = true;
    bool exist = false;
    rep(i,s.size()){
        if (i == 0) {
            if (s[i] != 'A')
            can = false;
        }
        else if (i >= 2 && i <= s.size()-2){
            if (s[i] == 'C' ) {
                if (exist) can = false;
                else exist = true;
            }
            if (s[i] != 'C' && isupper(s[i]))  can = false; 
        }
        else{
            if (isupper((s[i]))){
                //cout << "this" << endl;
                can = false;
            } 
        }
        //cout << i << endl;
        if (!can){
            cout  << "WA" << endl;
            return 0;
        }
    }
    if (exist && can) cout << "AC" << endl;
    else cout << "WA" << endl;
    return 0;

}
