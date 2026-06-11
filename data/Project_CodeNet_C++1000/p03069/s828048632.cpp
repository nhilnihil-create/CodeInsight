#include <bits/stdc++.h>
using namespace std;
#define LL long int

const LL MOD = pow(10,9) + 7;

int main(){
    int n;
    cin >> n;
    string s;
    char c;
    LL count1 = 0,count2 = 0;
    for(int i = 0; i < n; ++i){
        cin >> c;
        if(c == '.') count1++;
        s += c;
    }

    if(count1 == n || count1 == 0){
        cout << 0 << endl;
    }else{

    LL ans = MOD;

    for(int i = 0; i < n; ++i){
        ans = min(count1 + count2,ans);
        if(s[i] == '.') count1--;
        if(s[i] == '#') count2++;
        ans = min(count1 + count2,ans);
    }

    cout << ans << endl;

    }


    return 0;
}