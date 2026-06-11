#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair

using ll = long long;
using namespace std;

void solve() {
    int n;
    cin>>n;
    float t, a;
    cin>>t>>a; float h[10001]; float m=INT_MAX;
    for(int i =0;i<n;i++){
        cin>>h[i];
        h[i] = t-(h[i]*0.006);
        m = min(abs(h[i]-a), m);
    }
   // cout<<m<<'\n';
    for(int i=0;i<n;i++){
        if(abs(h[i]-a)==m){
            cout<<i+1<<'\n';
            break;
        }
    }

}

int main() 
{
    std::ios::sync_with_stdio(false); \
        std::cin.tie(NULL);
    int test;
    test=1;
    while (test--) {
        solve();
    }
    return 0;
}