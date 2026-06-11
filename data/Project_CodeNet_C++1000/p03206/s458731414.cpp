#include <bits/stdc++.h>
using namespace std;
#define rep(i,c) for(int i=0;i<c;++i)
int main(){
 int a;
 cin >> a;
 if(a==25){
   cout << "Christmas" << endl;
 }else if(a==24){
   cout << "Christmas" << " " << "Eve" << endl;
 }else if(a==23){
   cout << "Christmas" <<" " <<"Eve" <<" "<< "Eve" << endl;
 }else{
   cout << "Christmas" <<" "<< "Eve"<<" " << "Eve" <<" " << "Eve" << endl;
 }
 return 0;
}