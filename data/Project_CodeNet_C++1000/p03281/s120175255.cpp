#include <bits/stdc++.h>
using namespace std;
#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;
  
void f(int n) {
  	vector<int> prime{3, 5,	7,	11,	13,	17,	19,	23,	29,	31,	37};
  	int ans = 0;
	forn(i,9){
      for(int j = i+1; j < 10; j++){
        if(prime.at(i)*prime.at(j)*prime.at(j)*prime.at(j) <= n){
          ans++;
          //cout << prime.at(i) << "*" << prime.at(j)<< "^3 ="<< prime.at(i)*prime.at(j)*prime.at(j)*prime.at(j)  << endl;
        }
       if(prime.at(j)*prime.at(i)*prime.at(i)*prime.at(i) <= n){
          ans++;
          //cout << prime.at(j) << "*" << prime.at(i)<< "^3 ="<< prime.at(j)*prime.at(i)*prime.at(i)*prime.at(i)  << endl;
        }
      	for(int k = j+1; k < 11; k++){
        		if(prime.at(i)*prime.at(j)*prime.at(k) <= n){
		          //cout << prime.at(i) << "*" << prime.at(j)<< "*" << prime.at(k) << "="<<  prime.at(i)*prime.at(j)*prime.at(k) << endl;
                  ans++;
                }
        }
      }
    }
  	cout << ans << endl;
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int n;
  cin >> n;
  f(n);
  return 0;
}