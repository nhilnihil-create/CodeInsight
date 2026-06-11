
#include <bits/stdc++.h>
using namespace std;
#define ll long long
typedef std::vector<ll> vi;
int visited[100005] = {0} ;
long long int ans = 0 ;
long long int n , c ;



int main() {

  cin >> n >> c ;
  long long int total[n + 1] = {0};
  std::vector< pair<long long int , long long int > > a ;
  for (int i = 0; i < n; ++i)
  {
    long long int rr,  ff ;

    cin >> rr >> ff ;
    a.push_back(pair<long long int , long long int>(rr, ff));

  }
  a.push_back({0, 0});
  sort(a.begin(), a.end() );

  for (int i = 1; i <= n; ++i)
  {

    total[i] = total[i - 1] + a[i].second ;
  }

  long long best[n + 1] = {0};
  long long best2[n+1] = {0};
  long long curbest = 0 ;
  long long curbest2 = 0 ;
  for (int i = 1; i <= n; ++i)
  {
    curbest = max(curbest , total[i - 1] - ( 2* a[i - 1].first));
    best[i] = curbest;
    curbest2 = max(curbest2 , total[i - 1] - (  a[i - 1].first));
    best2[i] = curbest2;

  }
  long long b[n + 1] = {0};

  for (int i = 1; i <= n; ++i)
  {
    b[i] = total[n] - total[i - 1];
  }

  for (int i = 0; i <= n; ++i)
  {
    ans = max(total[i] - a[i].first, ans);
  }
  for (int i = 0; i <= n; ++i)
  {
    ans = max(total[n] - total[i] - c +  a[i].first , ans);
  }
  for (int i = 0; i <= n; ++i)
  {
    ans = max(best[i] + b[i] -  (c - a[i].first) , ans);
    ans = max(best2[i] + b[i] - 2 *  (c - a[i].first) , ans);
  }








  cout << ans << endl;


}
