#include<bits/stdc++.h>
#define fast ios::sync_with_stdio(false);cin.tie(NULL)
using namespace std;
#define int long long
#define MOD 1000000007
typedef vector<int> vi;
typedef pair<int,int> pi;
#define inf 1e18
#define For(i,a,b) for (int i = a; i < b; i++)
#define Rep(i,a,b) for (int i = a; i <= b; i++)
#define ps(x,y) fixed << setprecision(y) << x 
#define pb push_back 
#define mp make_pair 

int findXOR(int n) {
    int mod = n % 4;
    if(mod == 0) return n;
    else if(mod == 1) return 1;
    else if(mod == 2) return n+1;
    else if(mod == 3) return 0;
}

int findXOR(int a, int b) {
    return (findXOR(a-1) ^ findXOR(b));
}
 
int32_t main()
{
    fast;
    int a, b; cin >> a >> b;
    cout << findXOR(a, b);

    return 0;
}