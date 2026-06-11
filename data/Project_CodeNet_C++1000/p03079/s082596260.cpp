#include <bits/stdc++.h>
#define be(v) (v).begin(),(v).end()
#define pb(q) push_back(q)
#define era(t) t.erase(unique(be(t)),t.end())
#define doublecout(a) cout<<fixed<<setprecision(10)<<a<<endl;
typedef long long ll;
using namespace std;
const ll mod=1000000007,mod9=1000000009;
template <class T>inline T lcm(T a,T b){return (a*b/__gcd(a,b));}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int a,b,c;
    cin>>a>>b>>c;
    if(a==b && b==c)cout << "Yes"<<endl;
    else cout <<"No"<<endl;
    return 0;
}

