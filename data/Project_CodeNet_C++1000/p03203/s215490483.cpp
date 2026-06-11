#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std ;

int main(){
	int h,w,n ;
	cin >> h >> w >> n ;
	if(n==0){
	    cout << h << endl ;
	    return 0 ;
	}
	vector<pair<int,int>> a ;
	for(int i=0;i<n;i++){
		int x,y ;
		cin >> x >> y ;
		if(x<y) continue ;
		a.push_back(make_pair(x,y)) ;
	}
	if(a.size()==0){
	    cout << h << endl ;
	    return 0 ;
	}
	sort(a.begin(),a.end()) ;
	int ans = 0 ;
	int pos = 0 ;
	int j = 1 ;
	for(int i=1;i<h+10;i++){
	    if(i==h) break ;
	    bool ok = false ;
	    bool right = true ;
	    while(pos!=a.size()&&a.at(pos).first==i+1){
	        if(a.at(pos).second<=j&&ok==false) ok = true ;
	        if(a.at(pos).second==j+1) right = false ;
	        pos++ ;
	        if(pos==a.size()) break ;
	    }
	    if(ok) break ;
	    if(right) j++ ;
	    ans++ ;
	}
	cout << ans+1 << endl ;
}
