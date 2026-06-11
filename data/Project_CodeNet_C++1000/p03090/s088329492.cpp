#include <bits/stdc++.h>
using namespace std;
#define int long long
#define All(v) (v).begin(),(v).end()
int dy[8] = {-1,0,1,0,-1,1,1,-1};
int dx[8] = {0,1,0,-1,1,1,-1,-1};
const int mod = 1000000007;
const int inf = mod*mod;
const int d5 = 100100;
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin>>n;
    int a[110][110];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++)a[i][j]=0;
    }
    int cnt=0,x=n+(n-1)%2;
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            a[i][j]=(i+j!=x);
            cnt+=(i+j!=x);
        }
    }
    cout<<cnt<<endl;
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            if(a[i][j])cout<<i<<' '<<j<<endl;
        }
    }

}