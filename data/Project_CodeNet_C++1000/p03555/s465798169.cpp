#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i=0;i < (int)(n);i++)

int table[101][101];



int main(){
    int n;
    string s,t;
    cin >> s >> t;
    if(s[0] == t[2] && s[1] == t[1] && s[2] == t[0]) cout << "YES" << endl;
    else cout << "NO" << endl;


    return 0;
}