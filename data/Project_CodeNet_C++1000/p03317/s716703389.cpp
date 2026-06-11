#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
typedef long long ll;
typedef pair<int, int> pii;
const int inf=1010001000;
const ll  INF=1001000100010001000;
const int mod=(int)1e9+7;

int main(){
    int n,k;
    cin>>n>>k;
    vector<int>a(n);
    int one;
    rep(i,0,n){
        cin>>a.at(i);
        if(a.at(i)==1)one=i;
    }
    cout<<((n-1)+(k-2))/(k-1)<<endl;
return 0;
}