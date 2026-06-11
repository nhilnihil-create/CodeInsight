#include<bits/stdc++.h>
#define N 2000009
#define ll long long
#define ld long double
#define ff first
#define ss second
#define inf 1000000005
#define mod 1000000007
using namespace std;
int n, k, a[109];
string ans[2] = {"Second", "First"};
int main() {
    cin>>n>>k;
    for(int i=1;i<=n;i++) {
        cin>>a[i];
    }
    vector<bool> winf(k + 1);
    winf[0] = 0;
    for(int i=1;i<=k;i++) {
        for(int j=1;j<=n;j++) {
            if(a[j] <= i && winf[i - a[j]] == 0) {
                winf[i] = 1;
                break;
            }
        }
    }
    cout<<ans[winf[k]]<<endl;
}
