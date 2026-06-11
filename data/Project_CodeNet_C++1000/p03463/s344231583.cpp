#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0;i<n;i++)
#define erep(i,n) for(int i = 0;i<=n;i++)
#define rep1(i,n) for(int i = 1;i<n;i++)
#define erep1(i,n) for(int i = 1;i<=n;i++)
typedef long long ll;
#define vint vector<int>
#define vvint vector<vector<int>>
#define vstring vector<string>
#define vll vector<ll>
#define vbool vector<bool>
#define INF 1000000009

int main(){
    int n,a,b;
    cin >> n >> a >> b;
    if((a == 1 && b == 2) || (a == n && b == n-1)) cout << "Borys" << endl;
    else if(abs(a-b) % 2 == 0) cout << "Alice" << endl;
    else cout << "Borys" << endl;
}