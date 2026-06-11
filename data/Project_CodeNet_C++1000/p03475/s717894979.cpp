#include <bits/stdc++.h>
using namespace std;

inline int ceiling_div(int a, int b){ // ceiling(a/b)= floor((a+b-1)/b)
  return (a+b-1)/b;
}

int main(){
  using station= tuple<int, int, int>;
  int N,atTstart,forTwait,forTtrans;
  cin >> N;

  vector<station> data(N);
  for(int i=0; i<N-1; i++){
    cin >> forTtrans >> atTstart >> forTwait;
    data.at(i)= make_tuple(atTstart, forTwait, forTtrans);
  }
  data.back()= make_tuple(0, 1, 0);

  vector<int> ans(N);
  for(int s=0; s<N-1; s++){
    int atTarrive= 0;
    for(int i=s; i<N; i++){
      tie(atTstart, forTwait, forTtrans)= data.at(i);

      int atToff= atTstart+ forTwait* max(0, ceiling_div(atTarrive- atTstart, forTwait));
      atTarrive= atToff+ forTtrans;
    }

    ans.at(s)= atTarrive;
  }

  for(auto elem:ans){
    cout << elem << endl;
  }
}