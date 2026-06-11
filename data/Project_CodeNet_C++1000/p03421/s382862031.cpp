#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int maxn = 300100;

int n,a,b,ans[maxn];

int main() {
  //  freopen("in.txt","r",stdin);
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin>>n>>a>>b;
    if ((n<a+b-1) || (n > 1ll*a*b)) cout<<-1;
    else {
        int cur = n;
        for (int i=b;i>=1;i--) {
            if (cur-a > i-1) {
                for (int j=cur-a+1;j<=cur;j++) cout<<j<<" ";
                cur-=a;
            } else {
                for (int j=i;j<=cur;j++) cout<<j<<" ";
                cur=i-1;
                break;
            }
        }
        for (int i=cur;i>=1;i--) cout<<i<<" ";
    }
}
