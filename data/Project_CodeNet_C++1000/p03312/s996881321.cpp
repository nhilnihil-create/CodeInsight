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
const int N   = 2e5 + 5;

int P[N],S[N],I[N],n,ans = 1LL * mod * mod;

void f(int i, int j, int k){
    int a = P[i];
    int b = P[j] - P[i];
    int c = P[k-1] - P[j];
    int d = S[k];
    if(a == 0 || b == 0 || c == 0 || d == 0) return;
    ans = min(ans , max(max(a,b),max(c,d)) - min(min(a,b),min(c,d)));
}

signed main(){
    cin >> n;
    int j = 1;
    for(int i=1; i<=n; i++){
        scanf("%lld", &P[i]);
		P[i] += P[i-1];
        for(; j < i && 2*P[j] <= P[i];) j++;
        I[i] = j-1;
    }
    
	j = n;
    for(int i=n; i>=2; i--){
		S[i] = S[i+1] + P[i]-P[i-1];
        for(; j > i && 2*S[j] <= S[i];) j--;
    	f(I[i-1], i-1, j);
        f(I[i-1], i-1, j+1);
        f(I[i-1]+1, i-1, j);
        f(I[i-1]+1, i-1, j+1);
    }
        
    cout << ans;    
    return 0;
}