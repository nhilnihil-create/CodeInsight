#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
void READ() {
#define R READ();
#define INFI 0x3f3f3f3f
#define INFL 0x3f3f3f3f3f3f3f3f
#define MEMX(x,num) memset(x,num,sizeof(x))
#define prln(x) cout<<#x<<"="<<x<<endl
#define prt(x) cout<<x<<endl
#define prk(x) x<<" "
#define sz(x) int(x.size())
#define PB(x) push_back(x)
#define LINK(x,y) G[x].PB(y),G[y].PB(x)
#ifndef ONLINE_JUDGE
    freopen("A.in", "r", stdin);
#endif
    std::ios::sync_with_stdio(0);
    cin.tie(0);
    cout << fixed << setprecision(3);
}
///////////////////////////
const int N=5 +2e5;


int n;
int a[N];
int main() {
    
    cin >> n;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    sort(a,a+n);
    int ma=a[n-1],ans;
    int mi=INFI;
    for(int i=0;i<n-1;i++)
    {
        if(abs(2*a[i]-ma)<mi)mi=abs(2*a[i]-ma),ans=a[i];
    }
    cout<<ma<<" "<<ans;


    return 0;
}
