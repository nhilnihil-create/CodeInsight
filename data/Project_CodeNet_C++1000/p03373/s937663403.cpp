#include <bits/stdc++.h>

using namespace std;
using ll=long long;
const ll mod = 1e9 + 7;
int dy[] = {1, -1, 0, 0};
int dx[] = {0, 0, 1, -1};


int main() {
    int A,B,C,X,Y;
    cin>>A>>B>>C>>X>>Y;
    int ans=1e9;
    for(int i=0;i<=max(X,Y)*2;i+=2){
        int val=C*i;
        int restx=max(0,X-i/2),resty=max(0,Y-i/2);
        val+=restx*A+resty*B;
        ans=min(ans,val);
    }
    cout<<ans<<endl;
    return 0;
}
