#include <bits/stdc++.h>
#define be(v) (v).begin(),(v).end()
#define pb(q) push_back(q)
typedef long long ll;
using namespace std;
const ll mod=1000000007;
#define doublecout(a) cout<<fixed<<setprecision(10)<<a<<endl;

int main() {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);
    int a,b,k;
    cin>>a>>b>>k;
    for(int i=0;i<k;i++){
        if(i&1){
            if(b&1)b--;
            b/=2;
            a+=b;
        }else{
            if(a&1)a--;
            a/=2;
            b+=a;
        }
    }
    cout<<a<<" "<<b<<endl;
    return 0;
}
