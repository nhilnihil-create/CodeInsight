#include <bits/stdc++.h>
using namespace std;
#define rep(i,c) for(int i=0;i<c;++i)
int main(){
 string n,k;
 cin >> n >> k;
 if(n>k){
     cout<< ">" << endl;
 }else if(n<k){
     cout << "<" << endl;
 }else{
     cout << "=" << endl;
 }
  
return 0;
}