#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    string a,b,c;
    cin>>n>>a>>b>>c;

    int ans = 0;
    for(int i=0; i<n; i++) {
        if(a.at(i)!=b.at(i) && b.at(i)!=c.at(i) && c.at(i)!=a.at(i)) ans += 2;
        else if(a.at(i)!=b.at(i) || b.at(i)!=c.at(i)) ans++;
    }

    cout<<ans<<endl;

    return 0;
}