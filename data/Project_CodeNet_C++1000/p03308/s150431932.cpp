#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i=0; i<n; ++i)

int main(){
  /*
  int N;
    cin >> N;
    vector<int> a(N);
    for (int i=0; i<N; ++i){
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    cout << a[N-1] - a[0] << endl;
    */
   int n; cin >> n;
   vector<ll> a(n);
   rep(i,n) cin >> a[i];
   sort(a.begin(), a.end());
   cout << a[n-1]-a[0] << endl;
}