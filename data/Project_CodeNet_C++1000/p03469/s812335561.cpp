#include<bits/stdc++.h>
#define rep(i, n) for (int i=0;i<(n);i++)
using namespace std;
typedef long long ll;
 
int main(void){
    string s;
    cin>>s;
    string ans = "2018";
    ans += s.substr(4, 6);
    cout<<ans<<endl;
    return 0;
}