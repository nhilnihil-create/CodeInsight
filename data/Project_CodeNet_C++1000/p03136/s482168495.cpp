#include <bits/stdc++.h>
using namespace std;
#define rep(i,c) for(int i=0;i<c;++i)
int main(){
 int a;
 cin >> a;
 vector<int>b(a);
 rep(i,a){
   cin >> b[i];
 }
 sort(b.begin(),b.end());
 int d =0;
 rep(i,b.size()-1){
   d +=b[i];
 }
 if(d>b[a-1]){
   cout << "Yes" << endl;
 }else{
   cout << "No" << endl;
 }
 return 0;
}