#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
#include <set>
#include <map>
#include <queue>
using namespace std;
#define rep(i,n) for(int i = 0;i<n;i++)
const long long MOD = 1000000007LL;
const string alpha = "abcdefghijklmnopqrstuvwxyz";
int main(){
    string s;
    cin >> s;
    int w;
    cin >> w;
    rep(i,s.size()){
        if(i%w==0) cout << s[i];
    }
    cout << endl;
}