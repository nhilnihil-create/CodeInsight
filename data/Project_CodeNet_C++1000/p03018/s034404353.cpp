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
    string s;
    cin >> s;
    string ns = "";

    vector<string> ans;
    rep(i, s.size()){
        if(s[i] == 'A') {
            ns += 'A';
        } else if(s[i] == 'B' && s[min(i+1, (int)s.size()-1)] == 'C'){
            i++;
            ns += 'S';
        } else if(ns!=""){
            ans.push_back(ns);
            ns = "";
        }
    }
    if (ns!="") ans.push_back(ns);

    ll score = 0;
    rep(i, ans.size()){
        string ts = ans[i];
        reverse(ts.begin(), ts.end());

        int snum = 0;
        rep(j, ts.size()){
            if (ts[j]=='S'){
                snum++;
            } else {
                score += snum;
            }         
        }
    }

    //show(ans);

    cout << score << endl;
}

