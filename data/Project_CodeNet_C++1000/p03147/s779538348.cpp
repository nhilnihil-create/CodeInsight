#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = (a); i < (b); ++i)
#define all(x) begin(x), end(x)
typedef long long ll;
typedef pair<int, int> pii;
const int inf=1010001000;
const ll  INF=1001000100010001000;
const int mod=(int)1e9+7;

int main(){
    int n;
    cin>>n;
    vector<int>h(n);
    rep(i,0,n){
        cin>>h.at(i);
    }
    int c=0;
    rep(i,0,n-1){
        if(h.at(i)-h.at(i+1)>0){
            c+=h.at(i)-h.at(i+1);
        }
    }
    cout<<c+h.at(n-1)<<endl;
return 0;
}
