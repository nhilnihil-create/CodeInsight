#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#define rep(i, a, b) for(int i = a; i < (b); ++i)
using namespace std;
int main() {
    string S;
    cin >> S;
    long long ans = 0;
    long long index = 0;
    rep(j, 0, S.size()){
        if(S[j]=='B') {
            index++;
        }
    }
    rep(i, 0, S.size()-1){
        if(S[i]=='B') {
            index--;
            ans += ((S.size()-1)-index) - i;
        }
        
    }
    cout << ans << endl;

    return 0;
}
