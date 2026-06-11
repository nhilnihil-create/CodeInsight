#include <bits/stdc++.h>
using namespace std;


int main() {


    int64_t n;
    cin>>n;

    int64_t sum_min=100000000;
    for(int64_t a=1;a<n;a++){
      int64_t b=n-a;

      string swk1 = to_string(a);
      string swk2 = to_string(b);
      int64_t sum_wk=0;
      for(int64_t i=0;i<swk1.size();i++){
        sum_wk += swk1.at(i)-'0';
      }

      for(int64_t i=0;i<swk2.size();i++){
        sum_wk += swk2.at(i)-'0';
      }

      sum_min=min(sum_min,sum_wk);
    }

    cout<<sum_min<<endl;

	return 0;
}