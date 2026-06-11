#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
const ll INF=1LL<<60;
const ll mod=1000000007;

int main() {
    string s;
    cin>>s;
    int a1=0,a2=0;
    for(int i=0;i<s.size();i++){
        if(i%2==0){
            if(s[i]=='0') a2++;
            else a1++;
        }
        else{
            if(s[i]=='0') a1++;
            else a2++;
        }
    }
    cout<<min(a1,a2)<<endl;
}
