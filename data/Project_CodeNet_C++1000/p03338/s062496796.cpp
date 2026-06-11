#include <bits/stdc++.h>
#define rep(i, a, b) for (int i=a; i<(int)(b); i++)

using namespace std;

typedef vector<int> vi;

int main(void){
    long n; cin >> n;
    string s; cin >> s;
    
    vi lv(26,0);
    vi rv(26,0);
    rep(i,0,n) rv[s[i]-'a']++;
    
    int biggest = 0;
    
    rep(i,0,n){
        rv[s[i]-'a']--;
        lv[s[i]-'a']++;
        int cnt = 0;
        rep(j,0,26){
          if(lv[j]!=0 && rv[j]!=0) cnt++;
        }
        biggest = max(biggest, cnt);
    }
    cout << biggest;
    return 0;
}
