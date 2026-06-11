#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin>>t;

    while (t--) {
        LL a, b, c, d;
        cin>>a>>b>>c>>d;

        if (a<b)    {
            cout<<"No"<<"\n";
            continue;
        }
        a-=b;
        if (d<b)    {
            cout<<"No"<<"\n";
            continue;
        }

        if (c>=b) {
            cout<<"Yes"<<"\n";
            continue;
        }
        a%=b;
        long long g = __gcd(b, d);
        a%=g;
        long long mx = b-g+a;
        if (mx > c) cout<<"No"<<"\n";
        else        cout<<"Yes"<<"\n";
    }
}
