#include <iostream>
#include <cmath>
#include <iomanip>
#include <limits>
#include <string>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <map>
#include <list>
using namespace std;
typedef long long ll;
#define rep(i,n) for(ll i=0;i<(n);i++)

int main(){
    ll n,ans=0;
    cin >> n;
    string a,b,c;
    cin >> a >> b >> c;
    rep(i,n){
        if(a[i] == b[i] && b[i] == c[i]){}
        else if(a[i] != b[i] && b[i] != c[i] && c[i] != a[i]) ans+=2;
        else ans+=1;
    }
    cout << ans << endl;
}
