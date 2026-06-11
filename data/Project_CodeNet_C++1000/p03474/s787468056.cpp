#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i=0;i < (int)(n);i++)

int main(){
    int a,b;
    string s;
    cin >> a >> b >> s;
    bool f = true;
    if (s[a] == '-') f = true;
    else f = false;
    for (int i = 0;i < s.size();i++){
        if (i != a){
            if (s[i] == '-') f = false;
        }
    }    
    if (f) cout << "Yes" << endl;
    else cout << "No" << endl;

    return 0;
    
}