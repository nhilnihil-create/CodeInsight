#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD=1000000007;
#define INF 1LL<<30
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define all(x) (x).begin(),(x).end()


int main(){
    string s,t;
    cin>>s>>t;
    sort(all(s));
    
    sort(all(t));
    reverse(all(t));

    if (s < t) cout << "Yes" << endl;
	else cout << "No" << endl;
}


