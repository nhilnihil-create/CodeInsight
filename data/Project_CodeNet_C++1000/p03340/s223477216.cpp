#include <bits/stdc++.h>
using namespace std;

const int N=2e5+100;
const int mod=1e9+7;
typedef long long ll;


typedef pair<int,int> pa;

ll p[N];
int main()
{
    ios::sync_with_stdio(0);cin.tie(0);
    int n;cin>>n;
    for(int i=1;i<=n;i++){
        cin>>p[i];
    }
    int l=1,r=2;
    ll ans=1;
    ll k=p[1];
    while(r<=n){

        if((k&p[r])==0){
            ans+=r-l+1;
            k^=p[r];
            r++;

        }
        else{
            k^=p[l];
            l++;
        }
    }

    cout<<ans<<endl;
    return 0;
}
