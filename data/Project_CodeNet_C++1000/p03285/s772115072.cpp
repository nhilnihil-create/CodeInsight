#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;
using P = pair<int,int>;
const int MOD = 1000000007;

int main() {
    int n;
    cin>>n;
    for (int i=0; 4*i<=n; i++) {
        for (int j=0; 7*j<=n; j++) {
            if (4*i+7*j==n) {
                cout<<"Yes"<<endl;
                return 0;
            }
        }
    }
    cout<<"No"<<endl;
}   
