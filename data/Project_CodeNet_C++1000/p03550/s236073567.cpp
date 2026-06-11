#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
const int N=2e3+5;
int n,a[N],x,y;
int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin>>n>>x>>y;
    for(int i=0;i<n;i++)
        cin>>a[i];
    if(n>1)
        cout<<max(abs(a[n-2]-a[n-1]),abs(a[n-1]-y) ) <<'\n';
    else
        cout<<abs(a[0]-y)<<'\n';

    return 0;
}
