#include <bits/stdc++.h>
#define gb(i,j) ((i>>j)&1)

using namespace std;
int n,a[(1<<18)+10];
int cs[(1<<18)+10][2];
int main()
{
    #ifdef abcxyz
    freopen("a.inp", "r", stdin);
    freopen("a.out", "w", stdout);
    #endif
    cin >> n;
    a[(1<<n)]=0;
    for(int i=0; i<(1<<n); ++i)cin >> a[i],cs[i][0]=i,cs[i][1]=(1<<n);
    int mx=0;
    for(int i=1; i<(1<<n); ++i){
        for(int j=0; j<n; ++j)
        if(gb(i,j)){
            int t=i-(1<<j);
            if(cs[t][0]!=cs[i][1] && cs[t][0]!=cs[i][0] && a[cs[t][0]]>a[cs[i][1]]){
                cs[i][1]=cs[t][0];
                if(a[cs[i][1]]>a[cs[i][0]])swap(cs[i][1],cs[i][0]);
            }
            if(cs[t][1]!=cs[i][1] && cs[t][1]!=cs[i][0] && a[cs[t][1]]>a[cs[i][1]]){
                cs[i][1]=cs[t][1];
                if(a[cs[i][1]]>a[cs[i][0]])swap(cs[i][1],cs[i][0]);
            }
        }
        mx=max(mx,a[cs[i][1]]+a[cs[i][0]]);
        cout << mx<<endl;
    }
    return 0;
}
