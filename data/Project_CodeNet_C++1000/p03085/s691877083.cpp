#include <bits/stdc++.h>
using namespace std;
using ll =long long;
#define all(v) v.begin(),v.end()
 
int main() {
 map<char,char> S;
  S['A']='T';
  S['T']='A';
  S['C']='G';
  S['G']='C';
  char b;
  cin>>b;
  cout<<S[b]<<endl;
}
       
  