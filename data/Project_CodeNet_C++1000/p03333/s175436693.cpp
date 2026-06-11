#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void){
    int n;
    cin >> n;
    vector<int> l(n+1),r(n+1);
    for(int i=1;i<=n;i++){
        int a,b;
        cin >> a >>b;
        l[i]=a,r[i]=b;
    }
    sort(l.rbegin(),l.rend());
    sort(r.begin(),r.end());
    ll ans=0;
    for(int i=0;i<=n;i++){
        if(l[i]>r[i]){
            ans+=2*(l[i]-r[i]);
        }
    }
    cout << ans << endl;
    return 0;
}
