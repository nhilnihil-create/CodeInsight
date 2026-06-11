#include <bits/stdc++.h>
#define int  __int128
#define ff first
#define dd second
#define mp make_pair
#define pb push_back
#define pp pair<int,int>
#define N 200007 // check
#define M 1007
#define K 130
#define endl "\n"
using namespace std;

int n, t;

int tab[N];
int x;
int k = 1e18;
int inf = k*k;
int pref[N];

int get(int a, int b) {
    return pref[b+1]-pref[a];
}

int pot[N];

int price(int ile) {
    int res = 0;
    int ind = n-1;
    int kk = 1;
    while(ind >= 0) {
        int r = ind;
        int l = max(ind - ile + 1, (int)0);
        res += get(l,r)*pot[kk];
        if(kk == 1) res += get(l,r);
        kk++;
        ind = l-1;
    }
    return res;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    int64_t temp; cin >> temp; n = temp;
    cin >> temp; x = temp;
    pref[0] = 0;
    pot[0] = 0;
    pot[1] = 4;
    for(int i = 2; i <= n; ++i) {
        pot[i] = 1 + 2*i;
    }
    for(int i = 0; i < n; ++i) {
        cin >> temp; tab[i] = temp;
        pref[i+1] = pref[i] + tab[i];
    }
    int mini = inf;
    for(int ile = 1; ile <= n; ++ile) {
        mini = min(mini, x*ile+n*x + price(ile));
        //cout << "ile " << ile << " " << (ile+n)*x  << " pr " << price(ile) << endl;
    }
    //price(1);
    temp = mini;
    cout << temp << endl;
}