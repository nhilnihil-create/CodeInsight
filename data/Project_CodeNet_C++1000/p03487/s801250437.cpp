#include <bits/stdc++.h>
using namespace std;

int main(){
  int N;
  int tmp,cnt = 0;
  map<int,int> num_cnt;
  vector<int> num;
  cin >> N;
  for(int i = 0; i < N; i++){
    cin >> tmp;
  	if(num_cnt.count(tmp))
       num_cnt.at(tmp)++;
    else{
       num.push_back(tmp);
       num_cnt[tmp] = 1;
    }
  }
  for(int i = 0; i < num_cnt.size(); i++){
    int suuzi = num[i];
      if(num_cnt[suuzi] < suuzi)
        cnt += num_cnt[suuzi];
      else if(num_cnt[suuzi] > suuzi)
        cnt += num_cnt[suuzi] - suuzi;
  }
  
  cout << cnt << endl;
}
