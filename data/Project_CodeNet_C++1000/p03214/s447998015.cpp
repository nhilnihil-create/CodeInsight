#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main() {
  int N;
cin >> N;

double heikin = 0;
vector<double> A(N);
for( int i = 0; i < N; i++ ){
cin >> A.at(i);
heikin += A.at(i);
}

heikin = heikin/ (double)N;

double sa = 1000;
int ans;
for( int i = 0; i < N; i++){
if( abs( heikin - A.at(i) ) < sa ){
ans = i;
sa = abs( heikin - A.at(i) );
}
}

cout << ans << endl;




            
}
