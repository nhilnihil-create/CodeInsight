#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
#define INF 10000000000
using namespace std;
using ll = long long;
int main()
{
    int a,b;
    cin >> a >> b;
    int x;
    cin >> x;
    if((a+b)>=x&& a<= x){
        cout << "YES" << endl;
    }else{
        cout << "NO" << endl;
    }
}
