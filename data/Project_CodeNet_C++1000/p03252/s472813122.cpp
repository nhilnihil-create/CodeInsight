#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pii pair<int , int>
#define _FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define MAXX 1005

int main()
{
    _FastIO;

    string s , t;
    cin >> s >> t;
    int n = s.size();
    vector<bool> used(50 , false);
    vector<bool> visited(50 , false);
    vector<char> c(50);
    vector<char> ch(50);
    string ans = "Yes";
    for(int i = 0; i < n; i++){
        int x = int(s[i]) - 97;
        int y = int(t[i]) - 97;
        if(!used[x]){
            c[x] = y;
            used[x] = true;
        }
        else{
            if(y != c[x])
                ans = "No";
        }
        if(!visited[y]){
            ch[y] = x;
            visited[y] = true;
        }
        else{
            if(x != ch[y])
                ans = "No";
        }
    }
    cout << ans << endl;
    return 0;
}
