#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<(n); i++)
#define rep2(i,x,n) for(int i=x; i<(n); i++)
const long long INF = LLONG_MAX;
using namespace std;
using ll = long long;
using P  = pair<int, int>;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int main()
{
    string s;
    int A, B;
    cin >> A >> B;
    cin >> s;
    if(s.size() != A+B+1)
    {
        cout << "No" << endl;
        return 0;
    }
    int p = s.find('-');
    if(p != A)
    {
        cout << "No" << endl;
        return 0;
    }
    rep(i, s.size()) 
    {
        if(i == A) continue;
        if(!(0 <= (s[i] - '0') && (s[i] - '0') <= 9)) 
        {
          cout << "No" << endl;
          return 0;
        }
    }
    // ll a = stoll(s.substr(0, A));
    // ll a = stoll(s.substr(0, A));
    cout << "Yes" << endl;
    
    return 0;
}