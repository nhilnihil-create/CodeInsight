#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define per(i,n) for (int i = (n)-1; i >=0; --i)
using namespace std;
using ll = long long;
using vi = vector<int>;
using vv = vector<vi>;

int main(){
    int n,a,b;
    cin>>n>>a>>b;
    int ans = 0, j, count;
    for(int i=1; i<=n; i++){
        j = i;
        count = 0;
        while(j){
            count += j%10;
            j /= 10;
        }
        if(a<=count && count<=b)ans+=i;
    }
    
    cout << ans << endl;
    return 0;
}