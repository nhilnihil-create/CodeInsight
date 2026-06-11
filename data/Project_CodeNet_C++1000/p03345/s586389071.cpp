#include <bits/stdc++.h>
#define rep(i, a) for (int i = 0; i < (a); ++i)
#define REP(i, a, b) for (int i = (a); i < (b); ++i)
#define pb push_back
typedef long long ll;
typedef long double la;
using namespace std;
 
int main(){
    ll a,b,c,k;
    cin >> a >> b >> c >> k;
    if(k%2==0){
        cout << a-b << endl;
    }else{
        cout << b-a << endl;
    }
}