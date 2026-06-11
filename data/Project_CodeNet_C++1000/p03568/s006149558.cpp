#include <bits/stdc++.h>
#define pb push_back
#define rep(i,n) for(int i = 0;i < (n); ++i)
#define all(v) v.begin(),v.end()
#define sort_1(v) sort(v.begin(),v.end())
#define sort_2(v) sort(v.begin(),v.end(),greater<ll>())
typedef long long ll;
typedef long double la;
using namespace std;

int main(){
    int n,a=1,b=1;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        a *= 3;
        if(x%2 == 0) b *= 2;
    }
    cout << a-b << endl;
    return 0;
}