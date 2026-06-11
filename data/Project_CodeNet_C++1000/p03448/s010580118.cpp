#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define per(i,n) for (int i = (n)-1; i >=0; --i)
using namespace std;
using ll = long long;
using vi = vector<int>;
using vv = vector<vi>;

int main(){
    int a,b,c,x;
    cin>>a>>b>>c>>x;
    
    int ans = 0;
    
    for(int i=0; i<=min(a, x/500); i++){
        for(int j=0; j<=min(b, (x-(500*i))/100); j++){
            if((x-500*i-100*j)/50<=c)ans++;
        }
    }
    
    cout << ans << endl;
    
    return 0;
}
