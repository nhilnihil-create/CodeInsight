#include <bits/stdc++.h>

using namespace std;
using ll = long long;
int main() {
    int n,k;
    cin>>n>>k;
    string s;
    cin>>s;
    int l=0,r=1;
    int tk=s[0]=='1'?0:1;
    int ts= 1;
int ms=ts;
    while(r<n){
        if(s[r-1]=='1'&&s[r]=='0')++tk;
        if(tk>k){
            while(l<r&&(s[l]!='0'||s[l+1]!='1')){
                ++l;
                --ts;
            }
            ++l;--ts;
            --tk;
        }
        ++ts;
        ++r;
        ms=max(ms,ts);
//cout<<ts<<" "<<tk<<endl;
    }
    cout<<ms<<endl;

    return 0;
}
