#include <bits/stdc++.h>
#define ll long long int
#define yorn(f) cout<<((f)?"Yes":"No")<<endl;
#define YORN(f) cout<<((f)?"YES":"NO")<<endl;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define println(x) cout << x << endl;
using namespace std;
int main()
{
    string s;
    cin >> s;
    yorn(
        s.find('a') != std::string::npos &&
        s.find('b') != std::string::npos &&
        s.find('c') != std::string::npos);
    return 0;
}