#include <bits/stdc++.h>
#define ll long long
using namespace std;
#define rep(i, n) for (int i = 0; i < n; i++)
using P = pair <int, int>;



int main(){
   string s;
   cin>>s;
   int k ;
   cin >> k;
   int n = s.size();
   vector<string> ST;
   for(int i=0;i<=n-1;++i){
       for(int j = 1; j<=5; ++j){
           ST.push_back(s.substr(i,j));
       }
   }
   sort(ST.begin(),ST.end());
   unique(ST.begin(),ST.end());
   cout << ST[k-1] <<endl;
      }