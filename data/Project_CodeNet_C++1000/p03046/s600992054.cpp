#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long  double lb;
int mod=1e9+7;
const int N=1e5+5;

int main()
{
    int m,k;cin>>m>>k;
    int n=(1<<m)-1;
    if(k>n) cout<<-1;
    else if(m==1){
        if(k!=1)cout<<0<<" "<<0<<" "<<1<<" "<<1;
        else cout<<-1;
    }
    else {
            for(int i=0;i<=n;i++){
                if(i!=k)cout<<i<<" ";
            }
            cout<<k<<" ";
            for(int i=n;i>=0;i--){
                if(i!=k)cout<<i<<" ";
        }
        cout<<k;
    }
    return 0;
}
