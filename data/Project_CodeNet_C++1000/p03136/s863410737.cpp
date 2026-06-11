
#include<bits/stdc++.h>
#define rep(i,n) for(int i=0; i<(n); i++)
using namespace std;
using ll=long long;

int main(){
 int n,max=0,sum=0;
 cin >> n;
 vector<int> l(n);
 rep(i,n) cin >> l[i];
 rep(i,n){
   if(l[i]>max){
     max=l[i];
   }
 }
 rep(i,n) 
   sum += l[i];
   
 if(sum>2*max) cout << "Yes" << endl;
 if(sum<=2*max) cout << "No" << endl;
 
}