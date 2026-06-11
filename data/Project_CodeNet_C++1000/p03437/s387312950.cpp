#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
  ll X,Y;cin>>X>>Y;
  cout<<(X%Y?X*(Y-1):-1);
}