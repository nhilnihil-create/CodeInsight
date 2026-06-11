#include<bits/stdc++.h>
using namespace std;


#define int long long
#define mp make_pair
#define pb push_back
#define st first
#define nd second

typedef long long ll;
typedef pair < ll , ll > pp;
const int mod = 1e9 + 7;
const int N   = 2e5 + 5;

int q,a,b,j,n,n2,x,y,mx,t;

signed main(){
    cin >> q;
    for(; q-- ;){
        cin >> a >> b;
        if(a > b) swap(a,b);
        t = 2*sqrt(a*b) + 1;

        for(j=t; j && j > t-20; j--){
            n = j;
            n2 = (n+1)/2;
            mx = 0;
            x = n2+1; y = n-x+1;
            if(x >= a) x++;
            if(y >= b) y++;
            mx = x * y;
            x = n2; y = n-x+1;
            if(x >= a) x++;
            if(y >= b) y++;
            mx = max(mx , x * y);
            x = n2-1; y = n-x+1;
            if(x >= a) x++;
            if(y >= b) y++;
            mx = max(mx , x * y);

            x = a; y = n-x+1;
            if(x >= a) x++;
            if(y >= b) y++;
            mx = max(mx , x * y);
            x = n-b+1; y = n-x+1;
            if(x >= a) x++;
            if(y >= b) y++;
            mx = max(mx , x * y);

            if(mx < a*b) break;
        }

        cout << j << endl;
    }

    return 0;
}