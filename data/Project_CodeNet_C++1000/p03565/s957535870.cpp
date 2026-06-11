#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    string t;
    int check;
    int pip = 0;
    
    cin >> s;
    cin >> t;
    
    int ss = (int)s.size();
    int st = (int)t.size();
    
    string ans;
    
    for (int i = 0;i < ss;i++){
        ans += 'z';
    }
    
    for (int i = 0;i <= ss-st;i++){
        string res = s;
        check = 1;
        for (int j = 0;j < i;j++){
            if (res[j] == '?'){
                res[j] = 'a';
            }
        }
        for (int j = 0;j < st;j++){
            if (res[i+j] == '?'){
                res[i+j] = t[j];
            }
            else if (res[i+j] != t[j]){
                check = 0;
            }
        }
        for (int j = st+i;j < ss;j++){
            if (res[j] == '?'){
                res[j] = 'a';
            }
        }
        if (check && res.compare(ans) <= 0){
            ans = res;
            pip = 1;
        }
     }
    if (pip)
	cout << ans << endl;
    else
    cout << "UNRESTORABLE" << endl;
    return 0;
}