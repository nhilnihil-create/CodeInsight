#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
#include <cmath>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)

int main(){
    string s;
    cin >> s;
    int ans=0,cnt=0, s_size;
    s_size = s.size();
    rep(i,s_size){
        rep(j,s_size-i){
            if(s[i+j] == 'A' || s[i+j] == 'C' || s[i+j] == 'G' || s[i+j] == 'T') {cnt++;}
            else break;
        }
        if(ans < cnt) ans = cnt;
        cnt = 0;
    }
    cout << ans << endl;
}