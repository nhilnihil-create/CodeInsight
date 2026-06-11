#include <bits/stdc++.h>
using namespace std;

int main(){
  int N;
  cin >> N;

  vector<int64_t> data2(N);
  vector<int64_t> data1(N);
  for(int i=0; i<N; i++){
    cin >> data2.at(i);
  }
  for(int i=0; i<N; i++){
    cin >> data1.at(i);
  }

  int64_t sum2= 0;
  int64_t sum1= 0;
  int64_t cnt2= 0;
  int64_t cnt1= 0;
  for(int i=0; i<N; i++){
    sum2+= data2.at(i);
    sum1+= data1.at(i);

    int64_t diff= data1.at(i)- data2.at(i);
    if(diff < 0){
      cnt1+= -diff;
    }
    else if(diff % 2==0){
      cnt2+= diff/2;
    }
    else{
      cnt2+= (diff+1)/ 2;
      cnt1++;
    }
  }
  int64_t Nop= sum1- sum2;
  string ans= (cnt1 <= Nop && cnt2 <= Nop) ? "Yes"
                                           : "No";

  cout << ans << endl;
}