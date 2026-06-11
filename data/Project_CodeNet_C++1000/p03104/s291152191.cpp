#include<bits/stdc++.h>
using namespace std;

#define Q int t; scanf("%d", &t); for(int q=1; q<=t; q++)
typedef long long int lli;
typedef pair<int, int> pi;
typedef pair<lli, int> pii;

vector<lli> flo(lli b)
{
    vector<lli> cn(45);
    for(int i=1; i<43; i++){
        lli x = 1LL<<i;
        lli div = b/x;
        cn[i-1] += div*(x/2);
        lli mod = b%x;
        cn[i-1] += max(0LL, mod-(x/2));
    }
    return cn;
}

int main()
{
    lli a, b;
    cin >> a >> b;
    b++;
    vector<lli> vb = flo(b);
    vector<lli> va = flo(a);
    for(int i=0; i<45; i++){
        vb[i] -= va[i];
    }
    lli ans = 0;
    for(int i=0; i<45; i++){
        if(vb[i]%2){
            ans += 1LL<<i;
        }
    }
    cout << ans << "\n";

    return 0;
}
