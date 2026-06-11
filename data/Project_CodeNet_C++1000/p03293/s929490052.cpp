#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
using P = pair<int,int>;

int main(void){
    string s, t; cin >> s >> t;
    string ss = s;
    ss.append(s);

    int ans = 0;
    for(int i = 0; i < s.length(); i++){
        int flg = 0;
        for(int j = i; j < s.length() + i; j++){
            if(ss[j] == t[j-i]) flg++;
        }
        if(flg == t.length()){
            ans = 1;
            break;
        }
    }

    if(ans) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}