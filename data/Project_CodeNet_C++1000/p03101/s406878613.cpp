#include <bits/stdc++.h>
using namespace std;
#define rep(i,c) for(int i=0;i<c;++i)
int main(){
 int a,b,c,d;
 cin >> a>> b>> c>> d;
 if((a*b)!=(c*d)){
     cout << (a-c)*(b-d) << endl;
 }else{
     cout << 0 << endl;
 }
 return 0;
}