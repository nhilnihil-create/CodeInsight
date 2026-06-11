#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 100000 + 10;
int a[N];
int main(){
    int n; cin>>n;
    for(int i=0;i<n;i++) cin>>a[i];
    int ans = 0;
    for(int i=0,j=0;i<n;i=j){
        while(a[j]==a[i]) j++;
        ans += (j - i) / 2;
    }
    cout<<ans<<endl;
}
