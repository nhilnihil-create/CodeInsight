#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; i++)
#define rep2(i, x ,n) for(int i = x; i < n; i++)
#define repr(i, n) for(int i = n; i >= 0; i--)
#define INF 2e9
#define ALL(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
int main(){
    string x;
    cin >> x;
    int fx=0;
    rep(i,x.size())fx+=(int)(x[i]-'0');
    cout <<  (stoi(x)%fx==0?"Yes":"No");
    
    
	return 0;
}