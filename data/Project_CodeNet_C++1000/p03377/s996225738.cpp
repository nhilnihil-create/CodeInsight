#include <bits/stdc++.h>
using namespace std;
#define rep(i,c) for(int i=0;i<c;++i)
int main(){
 int a,b,c;
 cin >> a>> b>> c;
 bool yon = c>=a && c<=a+b;
 if(yon){
     cout << "YES" << endl;
 }else{
     cout << "NO" << endl;
 }
 return 0;
}