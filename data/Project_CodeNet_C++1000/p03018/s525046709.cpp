//解説AC
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main(){
    string s;
    cin >> s;
    
    long long ans = 0, count_a = 0;
    int len = s.length();
    rep(i, len){
        if(s.at(i) == 'A') count_a++;
        if(s.at(i) == 'B' && i != len-1){
            if(s.at(i+1) == 'C'){
                ans += count_a;
                i++;
            }
            else{
                count_a = 0;
            }
        }
        else if(s.at(i) == 'C') count_a = 0;
    }
    
    cout << ans << endl;
    return 0;
}