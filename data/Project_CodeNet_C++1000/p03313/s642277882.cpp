#include<bits/stdc++.h>
using namespace std;

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
const int N   = 1 << 18;

pp mx[N], mx2[N];

signed main(){
    int n;
    cin >> n;
	for(int i=0; i<(1 << n); i++){
        scanf("%d", &mx[i].st);
        mx[i].nd = i;
    }

    for(int i=0; i<(1 << n); i++)
    	for(int j=0; j<n; j++){
            if((i & (1 << j)) == 0){
                int t = i | (1 << j);
                if(mx[i].nd != mx[t].nd){	
                	if(mx[t].st < mx[i].st){
                        mx2[t] = mx[t];
                        mx[t] = mx[i];
                    }
                    else mx2[t] = max(mx2[t] , mx[i]);
                }
                mx2[t] = max(mx2[t] , mx2[i]);
    		}
        }
    
    int ans = 0;
    for(int i=1; i<(1 << n); i++){
        ans = max(ans , mx[i].st + mx2[i].st);
        printf("%d\n", ans);
    }
    return 0;
}