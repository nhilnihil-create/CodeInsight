#include<bits/stdc++.h>
using namespace std;
 
#define pb push_back
#define ll long long
#define maxn 1000005
#define fr(i,j,k) for(int i=j;i<k;i++)
#define f(n) fr(i,0,n)
#define f1(n) fr(i,1,n+1)
#define ms(i) memset(i,0,sizeof(i));
#define ms1(i) memset(i,-1,sizeof(i));
#define F first
#define S second
#define all(x) x.begin(), x.end()
const int mod = 1e9+7;

string s1, s2;
int n, m;
bool solve(int pos, int b, char inc,char dec) {
    int mi = pos;
    int mx = pos;
    f((int)s1.size()) {
        if (s1[i]==dec){
            mi--;
        }
        if (s1[i]==inc){
            mx++;
        }
        //cout << mx <<' '<<mi << '\n';
        if (mi < 1 || mx > b) {
            return 1;
        }
        if (s2[i]==dec){
            mx--;
        }
        if (s2[i]==inc){
            mi++;
        }
        mi = min(mi,b);
        mx = max(mx,1);
    }
    return 0;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int k, x, y;
    cin >> n >> m >> k >> x >> y;
    cin >> s1 >> s2;
    if (solve(y,m,'R','L') || solve(x,n,'D','U')) {
        cout << "NO\n";
    }
    else {
        cout << "YES\n";
    }
    
}
