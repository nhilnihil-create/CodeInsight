#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1e9+7;
const long long INF = 1e15;

int main(){
    string s;
    cin >> s;
    string t;
    int n = s.size();
    t = s;
    reverse(t.begin(),t.end());
    int a = 0,b = 0;
    for(int i = 0; min(i+a,i+b) < n; i++){
        if(s[i+a] != t[i+b]){
            if(s[i+a] == 'x') b--;
            else if(t[i+b] == 'x') a--;
            else {
                cout << -1 << endl;
                return 0;
            }
        } 
        //cout << a << " " << b << endl;
    }
    int ans = -(a+b);
    ans /= 2;
    cout << ans << endl;
    return 0;
}