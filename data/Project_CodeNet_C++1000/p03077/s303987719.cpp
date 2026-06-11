#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ll long long
int main(){
    ll n,a,b,c,d,e;
    cin >> n >> a >> b >> c >> d >> e;
    ll saisyo =  min(a,min(b,min(c,min(d,e))));
    ll k = n/saisyo;
    if(n%saisyo != 0) k++;
    cout << k +4 << endl;
    
}