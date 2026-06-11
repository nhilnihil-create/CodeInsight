#include <bits/stdc++.h>
#include <cstring> 
using namespace std;
#define fast std::ios::sync_with_stdio(false);cin.tie(NULL);
#define pb push_back
#define int long long int
#define F first
#define mem(a,b) memset(a,b,sizeof(a))
#define S second
#define MOD 1000000007
#define in_range(x, y, r, c) (x < r && y < c && x >= 0 && y >= 0)
#define MAXN 100008
#define MAXI 100000000007

signed main(){
 
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    #ifdef _DEBUG
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    bitset<4000003> b;
    b[0] = 1;
    int sum=0;
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
    	cin>>a[i];
    	b = b|(b<<a[i]);
    	sum+=a[i];
    }
    int mid = sum/2 + sum%2;
    while(mid&&!b[mid])
    	mid++;
    cout<<mid<<endl;
}