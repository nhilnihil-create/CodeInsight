#include<iostream>
#include<vector>
#include<algorithm>
#include<cassert>
#include<functional>
#include<set>
using namespace std ;
#define rep(i,n) for( int i = 0 ; i < n ; i++ )
typedef long long ll ;

int main(){
    int n , m , k ;
    cin >> n >> m >> k ;
    set<int> A ;
    rep(i,k) if(n + i <= m ) A.insert(n + i);
    rep(i,k) if(m - i >= n ) A.insert(m - i);
    for(auto p : A) cout << p << endl;
}