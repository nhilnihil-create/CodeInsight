#include <bits/stdc++.h>
#define ll long long int
#define yorn(f) cout<<((f)?"Yes":"No")<<endl;
#define YORN(f) cout<<((f)?"YES":"NO")<<endl;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(), (x).end()
#define put(x) cout << x << endl;
#define println(x) cout << x << endl;
using namespace std;
int main()
{
    int n;
    string s;
    cin >> n >> s;
    
    string u = s;
    sort(all(u));
    u.erase(unique(all(u)), u.end());

    int best = 0;
    rep(i, n-1) {
        string s1 = s.substr(0, i+1);
        string s2 = s.substr(i+1);
        int c = 0;
        rep(j, u.size()) {
            if (s1.find(u[j]) != std::string::npos && s2.find(u[j]) != std::string::npos) {
                //　どっちにも含まれる
                c++;
            }
        }
        best = max(best, c);
    }

    put(best);

    return 0;
}