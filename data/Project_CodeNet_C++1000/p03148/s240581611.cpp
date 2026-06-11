#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int M=100010;

struct node{
	ll v , x;
}a[M];

ll vis[M];

bool cmp (node x,node y){
	return x.v > y.v;
}

int n , k;
ll cnt, tp ,res,ans;
int main(){
	cin >> n >> k ;
	for (int i = 1 ; i <= n ; i ++ ){
		int a1 , b ;
		cin >> a1 >> b ;
		a[ i ].x = a1 ;
		a[ i ].v = b ;
	}
	sort (a + 1 , a + n + 1 , cmp );
	stack<ll> s;
    for (int i = 1 ;i <= n ;i ++){
        if(cnt < k){
                if( vis [ a [ i ].x ] == 0 ){
                    vis [ a [ i ].x ]=1;
                    tp ++;
                }
				else{
                    s.push( a[ i ].v );
                }
                res+=a[i].v;
                cnt++;
                ans=max(ans,res+1ll*tp*tp);
        }
        else{
            if(s.empty()) break;
            if(vis[a[i].x]) continue;
            vis [ a [ i ] . x ]=1;
            tp ++;
            res -= s.top();
            res += a[i].v;
            s.pop();
            ans=max( ans , res + tp * tp );
        }
    }
    printf("%lld\n" , ans);
    return 0;
}