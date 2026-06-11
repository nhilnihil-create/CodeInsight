#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1e9+7;
int gcd(int a, int b){
   if (a%b == 0){
       return(b);
   }
   else{
       return(gcd(b, a%b));
   }
}
int main() {
    int n,x;
    cin >> n >> x;
    vector<int>dist(n+1);
    for(int i=0;i<n;i++){
        cin >> dist[i];
    }
    dist[n]=x;
    sort(dist.begin(),dist.end());
    int ans=dist[1]-dist[0];
    for(int i=0;i<n;i++){
        ans = gcd(ans,dist[i+1]-dist[i]);
    }
    cout << ans << endl;
}