#include<bits/stdc++.h>
#define rep(i,n) for(int i=0; i<(n); i++)
using namespace std;
using ll=long long;

int main(){
 int n;
 cin >> n;
 vector<tuple<string, int,int>> t(n);
 rep(i,n){
   string s;
   int point;
   cin >> s >> point;
   t[i]=make_tuple(s,-point,i+1);
 }
 sort(t.begin(),t.end());
 
 rep(i,n){
   string s;
   int point;
   int a;
   tie(s,point,a)=t[i];
   cout << a << endl;
 }
}