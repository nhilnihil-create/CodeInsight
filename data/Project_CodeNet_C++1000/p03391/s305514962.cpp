#include<bits/stdc++.h>
using namespace std;

#define int long long

#define mp make_pair
#define pb push_back
#define st first
#define nd second

typedef pair < int , int > pp;
const int mod = 1e9 + 7;
const int N   = 2e5 + 5;

int n,i,x,y,t,mn;

signed main(){
    cin >> n;
    mn = mod;
    for(i=1;i<=n;i++){
        cin >> x >> y; 
        if(x > y) mn = min(mn , y);
        t += x;
    }
    
    cout << (mn == mod ? 0 : t - mn);
    return 0;
}