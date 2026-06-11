#include <bits/stdc++.h>
using namespace std;

int main() {
  using tsii = tuple<string, int, int>;
  using vtsii = vector<tsii>;
  
  using pii = pair<int, int>;
  using vpii = vector<pii>;
  
  int N;
  cin >> N;
  
  vtsii restaurant(N);
  
  for( int i=0; i<N; i++ ){
    tsii elem;
    cin >> get<0>(elem);
    cin >> get<1>(elem);
    get<2>(elem) = i;
    restaurant.at(i) = elem;
  }
  
  sort(restaurant.begin(), restaurant.end());
  
  for( int i=1; i<N; i++ ){
    for( int j=(i-1); j>=0; j-- ){
      if( get<0>(restaurant.at(j)) == get<0>(restaurant.at(j+1)) ){
        if( get<1>(restaurant.at(j)) < get<1>(restaurant.at(j+1)) ){
          tsii tmp = restaurant.at(j);
          restaurant.at(j) = restaurant.at(j+1);
          restaurant.at(j+1) = tmp;
        }
      }
      else{
        break;
      }
    }
  }
  
  for( int i=0; i<N; i++ ){
    cout << (get<2>(restaurant.at(i)) + 1) << endl;
  }
}
