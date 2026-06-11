#include <bits/stdc++.h>
using namespace std;

const int N=2e5+100;
const int mod=1e9+7;
typedef long long ll;


typedef pair<int,int> pa;
pa a[N];
int W[N];

int main()
{
    ios::sync_with_stdio(0);cin.tie(0);
    int n,m,d;
    cin>>n>>m>>d;
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=m;j++){
           int x;
           cin>>x;
           a[x]={i,j};
        }
    }

    for(int i=1;i<=d;i++){
         for(int j=i+d;j<=n*m;j+=d){
            W[j]=abs(a[j].first-a[j-d].first)+abs(a[j].second-a[j-d].second)+W[j-d];
           // cout<<abs(a[j].first-a[j-d].first)+abs(a[j].second-a[j-d].second)+W[j-d]<<endl;
         }
    }
   int q;cin>>q;
    while(q--){
        int l,r;
        cin>>l>>r;
        cout<<W[r]-W[l]<<endl;
    }

    return 0;
}
