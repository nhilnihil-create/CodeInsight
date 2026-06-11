#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, srt, end) for (long long i = (srt); i < (long long)(end); i++)

string s;
ll ans = 0;

int main(){
    cin >> s;
    ll N = s.size();
    ll i = 0, num = 0;
    while(i < N){
        if(s[i] == 'A') num++;
        else num = 0;
        if(i + 2 < N){
            if(s[i] == 'A' && s[i+1] == 'B' && s[i+2] == 'C'){
                ans += num;
                s[i+2] = 'A';
                num--;
                i++;
            }
        }
        i++;
    }
    cout <<  ans << endl;
    return 0;
}