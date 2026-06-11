#include<bits/stdc++.h>
using namespace std;

using i64 = int64_t;

int main(){
    string s;
    cin >> s;
    i64 ans = 0, cnt = 0;
    reverse(s.begin(), s.end());
    int n = s.size();
    for(int i=0;i<n;++i){
        if(i<n-1 && s[i] == 'C' && s[i+1] == 'B'){
            cnt++;
            i++;
        }else if(s[i] == 'A'){
            ans += cnt;
        }else{
            cnt = 0;
        }
    }

    cout << ans << endl;

    return 0;
}