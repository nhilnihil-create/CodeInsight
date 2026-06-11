#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<n; i++)
#define repd(i,a,b) for (int i=(a);i<(b);i++)
#define all(x) x.begin(),x.end()
typedef long long ll;
typedef pair<ll, ll> l_l;
typedef pair<int, int> i_i;
 
#define EPS (1e-7)
#define INF (1e9)
#define PI (acos(-1))

//
int main(void) {
    string s;
    cin >> s;
    if(s.size()==3){
        string tmp = "abc";
        tmp[0] = s[0];
        s[0] = s[2];
        s[2] = tmp[0];
    }
    cout << s << endl;
    return 0;
}