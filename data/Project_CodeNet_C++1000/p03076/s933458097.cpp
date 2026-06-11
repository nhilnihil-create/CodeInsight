#include <bits/stdc++.h>
using namespace std;
#define rep0(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i, n) for (int i = 1; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
using ll = long long;

int main(){
    vector<int>a(5),b(5),c(5);
    rep0(i,5){
        cin>>a[i];
        b[i]=a[i]%10;
        c[i]=(10-b[i])%10;
    }
    sort(all(c));
    reverse(all(c));
    int ans=0;
    rep0(i,5){
        ans+=a[i];
        ans-=b[i];
        if(b[i]!=0){
            ans+=10;
        }
    }
    ans-=c[0];
    cout<<ans<<endl;
}