#include<iostream>
#include<algorithm>
using namespace std ;

int main(){
int A , B , C ; 
cin >> A >> B >> C ;
int mx = max({A,B,C});
int ans=9*mx +A +B +C;
cout << ans << endl ;
return 0;
}