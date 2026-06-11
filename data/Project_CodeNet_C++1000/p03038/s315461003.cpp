#include<bits/stdc++.h>
#define ll long long
#define pb push_back 
using namespace std;

bool fun(const pair<int,int>& p1, const pair<int,int> & p2 ) { 
    return p1.second > p2.second ; 
}

void solve() {
    int n , m ; 
    cin >> n >> m ;
    vector<int> a(n) ;
    ll sum = 0 ; 
    for(int i =0 ; i < n; ++i) {
        cin >> a[i] ;
        sum += a[i] ; 
    }

    sort(a.begin(), a.end()) ; 
    vector<pair<int,int>> b(n) ; 
    int x , y ; 
    for(int i= 0; i < m ; ++i) {
        cin >> x >> y ; 
        b.pb(make_pair(x,y)) ;
    }
    sort(b.begin(), b.end(), fun) ;
    int cur = 0 ; 
    for(int i = 0; i < m ; ++i)  {
        int cnt = b[i].first ; 
        while(cnt && cur < n ) {
            if(b[i].second < a[cur]) {
                cout << sum ; 
                return ; 
            }
            sum += b[i].second - a[cur] ; 
            cnt-- ; 
            cur++;
        }
    }
    cout << sum ; 

}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL) ; 

	int t ; 
    // cin >> t ;
    t = 1 ; 
    while(t--)
        solve() ; 
    return 0;
}
