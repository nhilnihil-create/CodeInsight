#include<bits/stdc++.h>

using namespace std;

#define ll  long long
#define ld  double

#define sz(x)   (int)x.size()
#define all(x)  x.begin(),x.end()

#define pb  emplace_back
#define X   first
#define Y   second

const int   N   = 2e5 + 5;

typedef pair<int,int>   ii;

ii  F[1 << 18];

void upd(int i,int x)   {
    if (F[i].Y < x)
        F[i].Y = x;
    if (F[i].X < F[i].Y)
        swap(F[i].X,F[i].Y);
}

int main()  {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n;  cin >> n;

    for(int i = 0 ; i < (1 << n) ; ++i) {
        int x;  cin >> x;
        upd(i,x);
    }
    for(int i = 0 ; i < n ; ++i)
    for(int j = 0 ; j < (1 << n) ; ++j) if (j >> i & 1)
        upd(j,F[j ^ (1 << i)].X),
        upd(j,F[j ^ (1 << i)].Y);

    int ans = 0;

    for(int i = 1 ; i < (1 << n) ; ++i) {
        int nxt = F[i].X + F[i].Y;
        if (ans < nxt)
            ans = nxt;

        cout << ans << "\n";
    }
}
