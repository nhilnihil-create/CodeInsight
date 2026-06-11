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

    vector<bool> alpha(26);

    string ans = "";
    string tmp = "";
    if (s[0] != 'z') ans = s[0]+1;
    //cout << ans << endl;
    rep(i, s.size()){
        tmp += s[i];
        int num = s[i] - 'a';
        alpha[num] = true;
        
        bool ok = false;
        char parts;
        char next = (i == s.size()-1) ? -1 : s[i+1]-'a'; 
        for (int j = next + 1; j < 26; j++)
        {
            if (!alpha[j]) {
                ok = true;
                parts = j + 'a';
                break;
            }   
        }
        if (ok == true){
            ans = tmp + parts;
        }
        //cout << tmp << ";" << parts << ":" << (int)next <<endl;
    }

    if (ans == ""){
        cout << -1 << endl;
    } else {
        cout << ans << endl;
    }

}

