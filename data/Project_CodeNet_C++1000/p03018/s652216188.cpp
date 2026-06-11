#include <bits/stdc++.h>
#define loop2(i, s, n, a) for (int i = int(s); i < int(n); i += a)
#define loop(i, s, n) loop2(i, s, n, 1)
#define rep(i, n) loop(i, 0, n)

#define pb push_back
#define all(in) in.begin(),in.end()

using ll = long long;
using ull = unsigned long long;
using namespace std;

int main(){
    string s; cin >> s;
    int n = s.length();

    string count = "";
    ll ans = 0;
    int num = 0;

    while(num+1 < n){
        if(s[num] == 'A'){
            count += "A"; num++;
        }
        else if(count.length() && s[num] == 'B' && s[num+1] == 'C'){
            count += "D"; num++; num++;
        }
        else if(count.length()){
            int count2 = count.length();
          	ll jj = 0;
            rep(j,count2) if(count[j] == 'D') { ans += j-jj; jj++;}
            count = ""; num++;
        }
        else num++;
    }
    int count2 = count.length();
    ll jj = 0;
    rep(j,count2) if(count[j] == 'D') { ans += j-jj; jj++;}

    cout << ans << endl;
}

