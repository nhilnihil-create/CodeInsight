#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std ;
using ll = long long ;
using vll = vector<ll> ;
#define all(v) v.begin(),v.end()

int main(){
	ll x,y,z,k ;
	cin >> x >> y >> z >> k ;
	vll a(x),b(y),c(z) ;
	for(auto &i:a) cin >> i ;
	for(auto &i:b) cin >> i ;
	for(auto &i:c) cin >> i ;
	sort(all(a)) ; reverse(all(a)) ;
	sort(all(b)) ; reverse(all(b)) ;
	sort(all(c)) ; reverse(all(c)) ;
    priority_queue<ll> pq1,pq2 ;
    for(int i=0;i<x;i++) for(int j=0;j<y;j++) pq1.push(a.at(i)+b.at(j)) ;
    vll sum(min(k,x*y)) ;
    for(int i=0;i<min(k,x*y);i++){
        sum.at(i) = pq1.top() ;
        pq1.pop() ;
    }
    for(int i=0;i<min(k,x*y);i++){
        for(int j=0;j<z;j++){
            pq2.push(sum.at(i)+c.at(j)) ;
        }
    }
    for(int i=0;i<k;i++){
        cout << pq2.top() << endl ;
        pq2.pop() ;
    }
}