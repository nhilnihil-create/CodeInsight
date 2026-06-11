#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define rep1(i, n) for(int i = 1; i <= (int)(n); i++)
#define show(x) {for(auto i: x){cout << i << " ";} cout<<endl;}
#define showm(m) {for(auto i: m){cout << m.x << " ";} cout<<endl;}
typedef long long ll;
typedef pair<int, int> P;
ll gcd(int x, int y){ return y?gcd(y, x%y):x;}
ll lcm(ll x, ll y){ return (x*y)/gcd(x,y);}


int main()
{
    int n;
    cin >> n;
    vector<string> s(n);
    rep(i, n){ cin >> s[i];}


    int ans = 0;
    int bscore = 0;
    int ascore = 0;
    bool ne = false; //ばらばらのがいる
    rep(i, n){
        bool aok = false;
        bool bok = false;
        if (s[i][0] == 'B') bok = true;
        if (s[i][s[i].size()-1] == 'A') aok = true;
        for (int si = 0; si < s[i].size()-1; si++)
        {
            if (s[i][si] == 'A' && s[i][si+1] == 'B'){
                ans++;
            }
        }
        if ((aok&&!bok) || (!aok&&bok)){
            ne = true;
        }
        if (aok) ascore++;
        if (bok) bscore++;
    }
    int plus = min(ascore, bscore);

    if (plus != 0 && !ne){
        plus--;
    }
    ans += plus;
    cout << ans << endl;
}

