#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;
using P = pair<int,int>;
const int MOD = 1000000007;

int main() {
    int a,b,c,x,ans=0;
    cin>>a>>b>>c>>x;
    for (int i=0; i<=a; i++) {
        for (int j=0; j<=b; j++) {
            for (int k=0; k<=c; k++) {
                if (500*i+100*j+50*k==x) {
                    ans++;
                }
            }
        }
    }
    cout<<ans<<endl;
} 
