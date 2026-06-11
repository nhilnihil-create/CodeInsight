#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<n; i++)
#define cans cout << ans << endl
#define cyes cout << "Yes" << endl
#define cno cout << "No" << endl
typedef long long ll;


int main(){
    int a,b,c;
    cin >> a >> b >> c;
    int mx = max(max(a,b),c);
    int now = 3*mx-a-b-c;
    int ans = 0;
    if(now%2){
        ans = now/2+2;
    }
    else{
        ans = now/2;
    }
    cout << ans << endl;
    return 0;
}