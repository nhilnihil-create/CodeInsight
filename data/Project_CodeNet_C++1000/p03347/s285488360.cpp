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
    vector<int> a(n);
    for(int i=0;i<n;i++)cin>>a[i];
    if(a[0]!=0){
        cout<<-1<<endl;
        return 0;
    }else if(n==1){
        cout<<0<<endl;
        return 0;
    }
    for(int i=1;i<n;i++){
        if(a[i]-a[i-1]>1){
            cout<<-1<<endl;
            return 0;
        }
    }
    int res=0;
    a.push_back(0);
    for(int i=0;i<n;i++){
        if(a[i]>=a[i+1])res+=a[i];
    }
    cout<<res<<endl;
}