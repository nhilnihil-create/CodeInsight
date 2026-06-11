#include <bits/stdc++.h>
using namespace std;
#define	rep(i,n)	for(int i=0;i<n;i++)
int main() {
  int n;	cin >> n;
  pair<pair<string,int>,int>	x[n];
  rep(i,n){
    string s;	cin >> s;
    int p;	cin >> p;	p*=-1;
    x[i].first.first=s;
    x[i].first.second=p;
    x[i].second=i+1;
  }
  sort(x,x+n);
  rep(i,n)	cout << x[i].second << endl;
}