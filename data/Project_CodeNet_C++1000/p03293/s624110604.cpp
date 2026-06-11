#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair

using ll = long long;
using namespace std;

void solve() {
    string s, t;
    cin>>s>>t;
    for (int i =0;i<s.size();i++) {
        if(s==t){
            cout<<"Yes"<<'\n';
            return;
        } 
        s = s.substr(1, s.size()-1)+s.front();

    }
cout<<"No"<<'\n';

}

int main()
{
    std::ios::sync_with_stdio(false); \
        std::cin.tie(NULL);
    int test=1;
    // cin>>test;
    while (test--) {
        solve();
    }
    return 0;
}