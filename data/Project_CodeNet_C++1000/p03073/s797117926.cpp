#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main(){
	string s;
    cin >> s;
    int len = s.size();
    int cnt1 = 0;
    int cnt2 = 0;
    rep(i,len){
        if(i % 2 == 1){
            if(s[i] != '1') cnt1++;
        }else{
            if(s[i] != '0') cnt1++;
        }
    }

    rep(i,len){
        if(i % 2 == 1){
            if(s[i] == '1') cnt2++;
        }else{
            if(s[i] == '0') cnt2++;
        }
    }

    int ans = min(cnt1,cnt2);
    cout << ans << endl;
}