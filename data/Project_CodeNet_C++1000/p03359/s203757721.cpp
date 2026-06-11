#include <bits/stdc++.h>
using namespace std;
#define rep(i,c) for(int i=0;i<c;++i)
int main(){
 int a,b;
 cin >> a>>b;
 if(a==b){
    cout << b << endl;
 }else if(a>b){
    cout << a-1<< endl;
 }else{
    cout << a<< endl;
 }
 return 0;
}