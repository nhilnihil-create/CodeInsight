#include<bits/stdc++.h>
#define int long long
#define rep(i, n) for(int i = 0; i < (int)n; i++)
#define repa(i, s, n) for(int i = s; i < (int)n; i++)
using namespace std;
using ll = long long;
typedef vector<int> vi;
typedef pair<int, int> P;
#define rrep(i,a,b) for(int i=a;i>=b;i--)
#define MOD 1000000007
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }

int facctorialMethod(int k){
    int sum = 1;
    for (int i = 1; i <= k; ++i)
    {
        sum *= i;
    }
    return sum;
}

signed main(){
    int n;
    cin >> n;
    set<string> m, a, r, c, h;
    rep(i, n){
        string s;
        cin >> s;
        switch(s[0]){
            case 'M': m.insert(s); break;
            case 'A': a.insert(s); break;
            case 'R': r.insert(s); break;
            case 'C': c.insert(s); break;
            case 'H': h.insert(s); break;
            default: break;
        }
    }

    int sum = 0;
    sum += m.size() * a.size() * r.size();
    sum += m.size() * a.size() * c.size();
    sum += m.size() * a.size() * h.size();
    sum += m.size() * r.size() * c.size();
    sum += m.size() * r.size() * h.size();
    sum += m.size() * c.size() * h.size();
    sum += a.size() * r.size() * c.size();
    sum += a.size() * r.size() * h.size();
    sum += a.size() * c.size() * h.size();
    sum += r.size() * c.size() * h.size();

    int num = 0;
    num += (m.size() > 0)? 1: 0;
    num += (a.size() > 0)? 1: 0;
    num += (r.size() > 0)? 1: 0;
    num += (c.size() > 0)? 1: 0;
    num += (h.size() > 0)? 1: 0;
    
    int itr_max = facctorialMethod(num) / 6;

    cout << sum /* * itr_max  */<< endl;

}