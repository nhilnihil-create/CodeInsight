#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> P;
const int INF = numeric_limits<int>::max()/2;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    string s;cin>>s;
    int a=0,b=0,c=0;
    for(int i=0;i<(int)s.length();i++){
        if(s[i]=='a') a++;
        else if(s[i]=='b') b++;
        else c++;
    }
    if(max(a,max(b,c))-min(a,min(b,c))<=1) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
}
