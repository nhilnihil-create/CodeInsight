#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, n) for (int i = 1; i <= (int)(n); i++)

int main(){
  int N;
  cin >> N;

  vector<string> S(N);
  vector<int> P(N);

  set<string> town;

  for (int i = 0; i < N; i++)
  {
    cin >> S.at(i);
    cin >> P.at(i);
    town.insert(S.at(i));
  }

  vector<int> ans;

  for (auto val : town)
  {
    vector<int> point_list;
    for (int i = 0; i < N; i++)
    {
      if (S.at(i) == val){
        point_list.push_back(P.at(i));
      }
    }
    
    sort(point_list.rbegin(), point_list.rend());

    for (auto point : point_list)
    {
      for (int i = 0; i < N; i++)
      {
        if (P.at(i) == point)
        {
          ans.push_back(i + 1);
        }
      }
    }
  }  
   
  for (auto val : ans)
  {
    cout << val << endl;
  }
}