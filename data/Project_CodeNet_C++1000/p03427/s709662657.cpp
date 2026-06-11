#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ll long long
int main(){
    string s;
    cin >> s;
    int cnt=0;ll ans;
    bool hantei=false;
    if(s.size() == 1){
        cout << s <<endl;
        return 0;
    }
    for(int i=1; i<=s.size()-1; i++){
        if(s[i] == '9') cnt++;
        if(cnt == s.size()-1) hantei=true;
    }
    
    if(hantei){
        ans = s[0] -'0' + 9*(s.size()-1);
    }
    else{
        ans =s[0] -'0' + 9*(s.size()-1) -1;
    }
    cout << ans << endl;
    return 0;
}