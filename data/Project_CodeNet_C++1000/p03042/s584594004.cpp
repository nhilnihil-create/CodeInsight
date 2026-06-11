#include<bits/stdc++.h>
#define ll long long int

using namespace std;

const ll mod=1000000007;
const ll inf=1e18;

int main(){

  /*ll s;
  cin >> s;

  ll a=s/100;
  ll b=s%100;
  */
  string s;
  cin >> s;
  ll a=stoi(s.substr(0,2));
  ll b=stoi(s.substr(2,2));

  if(0<a && a<13 && 0<b && b<13)cout << "AMBIGUOUS" << endl;
  else if(0<a && a<13) cout << "MMYY" <<endl;
  else if( 0<b && b<13) cout << "YYMM" << endl;
  else cout << "NA" << endl;

}