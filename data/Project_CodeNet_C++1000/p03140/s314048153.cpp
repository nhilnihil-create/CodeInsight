#include <bits/stdc++.h>
#define rep(i,n) for (int i=0;i<(n);i++)
using namespace std;
using ll = long long;
using P = pair<int,int>;
 
 
int main() {
    int n;
    cin >> n;
    string a,b,c;
    cin >> a >> b >> c;
    int ans=0;
    rep(i,n){
        if((a.at(i)==b.at(i)&&b.at(i)!=c.at(i))||(a.at(i)!=b.at(i)&&b.at(i)==c.at(i))||(a.at(i)==c.at(i)&&a.at(i)!=b.at(i))){
            ans++;
        }
        else if(a.at(i)!=b.at(i)&&b.at(i)!=c.at(i)&&c.at(i)!=a.at(i)) ans+=2;
    }
    cout << ans << endl;
}
