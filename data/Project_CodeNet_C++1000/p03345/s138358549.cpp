#include<bits/stdc++.h>
using namespace std;
#define rep(i,n); for(int i = 0;i < (int)(n);i++)
#define all(x) (x).begin(),(x).end()
typedef long long ll;

int main(){
    ll a,b,c,k;
    cin >> a >> b >> c >> k;
    
    if(abs(a-b)>pow(10,18))cout << "Unfair" << endl;
    else if(k%2 == 0)cout << a-b << endl;
    else cout << b-a << endl;
    return 0;
}