#include<bits/stdc++.h>
using namespace std;

bool compare(tuple<string, int, int>, tuple<string, int, int>);

int main()
{
  int n;
  cin >> n;
  
  string s;
  int p;
  vector<tuple<string, int, int>> t_list(n);
  for (int i = 0; i < n; i++) {
    cin >> s >> p;
    get<0>(t_list.at(i)) = s;
    get<1>(t_list.at(i)) = p;
    get<2>(t_list.at(i)) = i + 1; // 1-origin の番号
  }
  
  sort(t_list.begin(), t_list.end(), compare);
  
  for (tuple<string, int, int> t : t_list) {
    cout << get<2>(t) << endl;
  }
}

bool compare(tuple<string, int, int> left, tuple<string, int, int> right)
{
  if (get<0>(left) != get<0>(right)) {
    return get<0>(left) < get<0>(right);
  }
  
  // 異なる2個に同じ点数がついていることはない
  return get<1>(left) > get<1>(right);
}