#include <bits/stdc++.h>
using namespace std;
int main(){
    //freopen("AT3857.01.inp","r",stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;    
    bitset<4000000> f;
    f[0]=1;
    int sa =0;
    for (int i=1; i<=n; i++){
        int x;
        cin >> x;
        f |= f<<x;
        sa+=x;
    }
    for (int i=((sa+1)>>1); i<=sa; i++){
        if (f[i]){
            cout<<i<<'\n';
            return 0;
        }
    }
}