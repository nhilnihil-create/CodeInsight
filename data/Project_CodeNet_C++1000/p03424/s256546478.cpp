#include <bits/stdc++.h>
using namespace std;
void debug() {cout<<endl;}
template<typename T,typename... Args>
void debug(T x,Args... args) {cout<<x<<" ";debug(args...);}
#define forn(i,a,b) for(int i=a;i<b;++i)
#define SZ(x) int(x.size())
#define pb push_back
#define F first
#define S second
#define endl "\n"
typedef long long ll;
typedef pair<int, int> pii;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    
     int n;
     cin >> n;
     
     set<int> st;
     while (n--) {
         char c;
         cin >> c;
         st.insert(c);
     }
     
     if (SZ(st) == 3) {
         cout << "Three\n";
     } else {
         cout << "Four\n";
     }
}
