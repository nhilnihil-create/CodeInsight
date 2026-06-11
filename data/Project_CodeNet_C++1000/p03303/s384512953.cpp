#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mod 1000000007

int main(){
    string s; cin >> s;
    int len = s.length();
    int w; cin >> w;
    if(w == 1){cout << s << endl; return 0;}
    for(int i = 1; i <= len; i++){
        if(i%w == 1) cout << s[i-1];
    }
    cout << endl;
    return 0;
}