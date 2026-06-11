//Fairness

#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,x,y) for(int i=x;i<y;i++)
#define gcd(a,b) __gcd(a,b)
#define lcm(a,b) (a/__gcd(a, b)*b)
#define range(a) (a).begin(),(a).end()
#define pb push_back
const int inf = 2147483647;


int main (){
    ll a,b,c,d;cin>>a>>b>>c>>d;
    d%=2;
    cout << (d ? b-a :a-b) << endl;
    return 0;
}