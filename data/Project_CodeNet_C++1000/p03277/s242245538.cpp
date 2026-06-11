#include<bits/stdc++.h>
using namespace std;

#define int long long

#define _   int v, int tl, int tr, int l, int r
#define tm  (tl + tr >> 1)
#define sol v+v, tl, tm, l, r
#define sag v+v+1, tm+1, tr, l, r
#define pb push_back
#define mp make_pair
#define st first
#define nd second
typedef pair < int , int > pp;
const int mod = 1e9 + 7;
const int N   = 1e5 + 5;

int F[N+N], A[N], n;

void up(int x, int t){
    for(; x < N+N; x += x&-x)
        F[x] += t;           
}
int qry(int x){
    int t = 0;
    for(; x ; x -= x&-x)
		t += F[x];
    return t;
}

signed main(){
    cin >> n;
    for(int i=1; i<=n; i++){
        scanf("%lld",&A[i]);
    }
        
    int l = 1;
    int r = mod;
    for(; l<r ;){
        int m = (l+r) >> 1;
		memset(F , 0 , sizeof F);
        up(0+N, 1);
        int p = 0;
        int asd = 0;
        for(int i=1; i<=n; i++){
            if(A[i] <= m) p++;
            else p--;
			asd += qry(p-1+N);
            up(p+N,1);
        }
        
        if(asd >= n*(n+1)/4 + 1) r = m;
        else l = m+1;
    }
    
    cout << l;
    return 0;
}