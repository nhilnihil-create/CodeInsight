#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define ALL(a)  (a).begin(),(a).end()
#define spa << " " <<

ll gcd(ll x, ll y)
{
    ll r;
    while((r = x % y) != 0)  
    {
        x = y;
        y = r;
    }
    return y;
}

int main(){
  ll n;
  cin >> n;
  vector<ll> a(n), b(n), c(n), d(n);
  ll i, j;
  for(i = 0; i < n; i++)
    cin >> a[i] >> b[i] >> c[i] >> d[i];
  string result;
  ll abuf, gcdbuf, maxbuf;
  
  for(i = 0; i < n; i++){
    if(a[i] < b[i] || b[i] > d[i])
      result = "No";
    else if(b[i] <= c[i] + 1)
      result = "Yes";
    else{
      abuf = a[i] % b[i]; //15
      //cout << "abuf" << abuf;
      //dbuf = d[i] % b[i];
      //0~cの余りが許容
      gcdbuf = gcd(b[i], d[i]); //1
      //cout << "gcdbuf" << gcdbuf;
      maxbuf = b[i] - gcdbuf + (abuf % gcdbuf); //16
      //cout << "maxbuf" << maxbuf;
      if(maxbuf <= c[i])
        result = "Yes";
      else
        result = "No";
    }

      
    cout << result << endl;
  }
   
  return 0;
}