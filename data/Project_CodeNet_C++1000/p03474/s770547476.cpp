#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;
using P = pair<int,int>;
const int MOD = 1000000007;
#define inf 1e9

int main() {
    int a,b;
    string s;
    cin>>a>>b>>s;
    rep(i,a+b-1) {
        if (i!=a) {
            if (s[i]=='-') {
                cout<<"No"<<endl;
                return 0;
            } 
        }
        else {
            if (s[i]!='-') {
                cout<<"No"<<endl;
                return 0;
            }
        }
    }
    cout<<"Yes"<<endl;
} 
