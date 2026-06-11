#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

typedef long long ll;
typedef pair<int, int> P;

const ll mod =  1000000007;
const int inf = 1e9;
const long long INF = 1LL << 60;   // INFの値は1152921504606846976

int dx[8] = {-1,-1,-1,0,0,1,1,1};
int dy[8] = {-1,0,1,-1,1,-1,0,1};


int main()
{
    string s;
    cin >> s;
    string t = "";
    int n = s.size();
    rep(i,n){
        if(i+1 < n && s[i] == 'B' && s[i+1] == 'C'){
            t += 'D';
            i++;
        }else{
            t += s[i];
        }
    }
    //cout << t << endl;
    ll ans = 0;
    ll tmp = 0;
    rep(i,n){
        if(t[i] == 'A'){
            tmp++;
        }else if(t[i] == 'D'){
            ans += tmp;
        }else{
            tmp = 0;
        }
    }
    cout << ans << endl;
}
