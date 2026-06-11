#include <bits/stdc++.h>
 
using namespace std;
typedef long long ll;
typedef vector<int> VI;
ll mm=1000000000;ll MM=mm+7;
#define rep(i, n) for(int i=0;i<n;i++)
#define PI 3.141592653589793

int main(){
 int n;
 cin >> n;
 VI h(n);
 ll sum=0;
 rep(i,n){
     cin >> h.at(i);
     sum+=h.at(i);
 }
 rep(i,n-1){
     if(h.at(i)>=h.at(i+1))sum-=h.at(i+1);
     else if(h.at(i)<h.at(i+1))sum-=h.at(i);
 }
 cout << sum << endl;

}