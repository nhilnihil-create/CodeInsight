#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
#define sfl(i,a,n) for (int i=a;i<n;i++)
#define ufl(i,a,n) for (int i=n-1;i>=a;i--)
#define SZ(x) ((int)(x).size())
#define endl '\n'
typedef long long ll;

ll power(ll a, ll b){
    ll res = 1;
    for(int i = 0; i<b; i++)
        res *= a;

    return res;
}

void init(){
    cin.tie(0);
    cin.sync_with_stdio(0);
}


int main()
{
    init();
    int x,y;
    cin >>x>>y;
    cout <<(x-1)*(y-1);
}
