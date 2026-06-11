#include <iostream>
#include <string>
#include <array>
#include <algorithm>
#include <vector>
#include <string>
#include <set>
#include <cctype>
#define int long long
using namespace std;

void printVector(const vector<int>& vec) {
    for (int value : vec) {
        cout << value << " ";
    }
    cout << endl;
}

signed main() {

    int a,b;
    string s;
    bool ans = true;

    cin  >> a >> b >> s;

    if(s.length() != (a+b+1)) ans = false;
    else {
        for(int i = 0; i < s.length(); i ++){
            if(i == a){
                if(s[i] != '-') ans = false;
            }else{
                if(!isdigit(s[i])) ans = false;
            }
        }
    }
    if(ans) cout << "Yes";
    else cout << "No";
    return 0;
}