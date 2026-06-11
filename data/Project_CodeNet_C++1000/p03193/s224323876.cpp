#include <bits/stdc++.h>
using namespace std ;

int main()
{ 
  int n, h, w ;
  cin >> n >> h >> w ;
  vector< pair<int64_t, int64_t> > data(n) ;
  for(int i = 0 ; i < n ; i++)
  {
    int64_t a, b ;
    cin >> a >> b ;
    data.at(i) = make_pair(a, b) ;
  }

  int count = 0 ;
  for(int i = 0 ; i < n ; i++)
  {
    int64_t a, b ;
    tie(a, b) = data.at(i) ;
    if(a >= h && b >= w)
    {
      count++ ;
    }
  }

  cout << count << endl ;
}
