#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;

int main(){
    string s; cin >> s;
    int n = s.length();
    bool check = 1;
    if(s[0] != '1' || s[n-1] != '0') check = 0;
    rep(i,n/2) if(s[i] != s[n-2-i]) check = 0;
    if(check){
        int from = 1, to = 2;
        rep(i,n-1){
            if(s[i] == '1'){
                printf("%d %d\n",from,to);
                from = to; to++;
            }
            else{
                printf("%d %d\n",to,from);
                to++;
            }
        }
    }
    else printf("%d",-1);
    return 0;
}