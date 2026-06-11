#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
#include <map>
#include <iomanip>
#include <stdlib.h>
#include <queue>

using namespace std;

const int nmax = 1e9 + 7;
const long long INF = 1e18;
const double PI = 2 * asin(1);
typedef long long ll;


int main(){
  int N; cin >> N;

  if (N == 3){
    cout << "2 3 25" << endl;
  }else{
    vector <int> ans;
    int now = 0;
    for (int i = 0; i < (N - N % 8) / 8; i++){
      ans.push_back(12 * i + 2);
      ans.push_back(12 * i + 3);
      ans.push_back(12 * i + 4);
      ans.push_back(12 * i + 6);
      ans.push_back(12 * i + 8);
      ans.push_back(12 * i + 9);
      ans.push_back(12 * i + 10);
      ans.push_back(12 * i + 12);
      now = 12 * i + 12;
    }

    if (N % 8 == 1){
      ans.push_back(now + 6);
    }else if(N % 8 == 2){
      ans.push_back(now + 3);
      ans.push_back(now + 9);
    }else if (N % 8 == 3){
      ans.push_back(now + 3);
      ans.push_back(now + 6);      
      ans.push_back(now + 9);      
    }else if(N % 8 == 4){
      ans.push_back(now + 2);  
      ans.push_back(now + 3);
      ans.push_back(now + 4);      
      ans.push_back(now + 9);       
    }else if (N % 8 == 5){
      ans.push_back(now + 2);
      ans.push_back(now + 4);      
      ans.push_back(now + 6);
      ans.push_back(now + 3);
      ans.push_back(now + 9);
    }else if (N % 8 == 6){
      ans.push_back(now + 2);
      ans.push_back(now + 4);      
      ans.push_back(now + 6);       
      ans.push_back(now + 3);
      ans.push_back(now + 9);      
      ans.push_back(now + 12); 
    }else if (N % 8 == 7){
      ans.push_back(now + 2);
      ans.push_back(now + 4);      
      ans.push_back(now + 6);       
      ans.push_back(now + 3);
      ans.push_back(now + 9);      
      ans.push_back(now + 10); 
      ans.push_back(now + 8);
    }

    for (int i = 0; i < N; i++){
      cout << ans[i];
      if (i != N - 1) cout << " ";
      else cout << endl;
    }
  }
  
  
  return 0;
}
