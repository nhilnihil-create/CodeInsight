#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
int n,m,c;
int b[25],a[25];
int s;
int ans;
int main(void){
    cin>>n>>m>>c;
    for(int i=0;i<m;i++){
        cin>>b[i];
    }
    while(n--){
        s=0;
        for(int i=0;i<m;i++){
            cin>>a[i];
            s+=a[i]*b[i];
        }
        s+=c;
        if(s>0){
            ans++;
        }
    }
    cout<<ans<<endl;

}

