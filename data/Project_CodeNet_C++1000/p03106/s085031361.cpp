#include <bits/stdc++.h>
#define rep0(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i <= (n); ++i)
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
typedef tuple<string, int, int> TU;
typedef tuple<int, int, int> TI;

int main()
{
    int a,b,k;
    cin >> a >> b >> k;
    ll res=0;
    ll now=__gcd(a,b);
    while(k>0){
        if(a%now==0&&b%now==0){
            k--;
        }
        now--;
    }
    cout << now+1 << endl;
}
