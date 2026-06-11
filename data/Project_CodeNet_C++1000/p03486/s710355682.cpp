#include<iostream>
#include<vector>
#include<algorithm>
#include<functional>
using namespace std;

int main()
{
  string s, t;
  cin >> s >> t;
  
  vector<char> ss, tt;
  for (int i = 0; i < s.size(); i ++)
    ss.push_back(s.at(i));
  for (int i = 0; i < t.size(); i ++)
    tt.push_back(t.at(i));
  
  // sのアナグラムの最弱(ss)とtのアナグラムの最強(tt)を比べる
  sort(ss.begin(), ss.end());
  sort(tt.begin(), tt.end(), greater<>{});
  
  // ttがssに勝ってたら勝ち抜け
  if (tt.at(0) > ss.at(0))
  {
    cout << "Yes";
    return 0;
  }

  // ttがssに負けてたら負け抜け
  if (tt.at(0) < ss.at(0))
  {
    cout << "No";
    return 0;
  }
  
  // 頭が同じときは一文字ずつ見ていって勝負
  if (tt.at(0) == ss.at(0))
  {
    int index = 0;
    while(ss.size() > 0 && tt.size() > 0)
    {
      // 勝ち抜け
      if (tt.at(index) > ss.at(index))
      {
        cout << "Yes";
        return 0;
      }
      // 負け抜け
      else if (tt.at(index) < ss.at(index))
      {
        cout << "No";
        return 0;
      }
      ss.erase(ss.begin());
      tt.erase(tt.begin());
    }
  }
  
  // 勝ち抜け、負け抜けが出ずにループが終わった時
  // 先にssとttのどちらが尽きたかで勝敗が確定
  if (tt.size() > 0)
  {
    cout << "Yes";
    return 0;
  }
  else
  {
    cout << "No";
    return 0;
  }

  return 0;
}