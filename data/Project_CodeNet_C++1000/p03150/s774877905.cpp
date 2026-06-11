#include <bits/stdc++.h>

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ll long long

using namespace std;


int main() {
    string k = "keyence";
    string s; cin >> s;
    string ans = "YES";
    int p = 0;

    bool d = false;
    bool d2 = false;
    int count = 0;
    int n = s.length();
    int left;

    while(1){
        if(s[p] == k[count]){
            count ++;
            if (count == 7) break;
            p ++;
        }else{
            left = 7-count;
            for(int i = n-left; i < n; i ++){
                if(s[i] != k[count]) ans = "NO";
                count ++;
            }
            break;
        }
    }

    cout << ans;


    return 0;
}









