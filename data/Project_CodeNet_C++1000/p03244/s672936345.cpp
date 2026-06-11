#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n;
  cin >> n;
  vector<int> v_odd(n / 2), v_even(n / 2);
  for(int i = 0; i < n; ++i) {
    if(i % 2 == 0) {
      cin >> v_odd.at(i / 2);
    }
    else {
      cin >> v_even.at(i / 2);
    }
  }

  sort(v_odd.begin(), v_odd.end());
  sort(v_even.begin(), v_even.end());

  vector<pair<int, int>> even_list, odd_list;
  int cnt = 0;
  int odd_comp = v_odd.at(0);
  for(int i = 0; i < v_odd.size(); ++i) {
    if(odd_comp == v_odd.at(i)) cnt++;
    else {
      odd_list.push_back({cnt, odd_comp});
      odd_comp = v_odd.at(i);
      cnt = 1;
    }
    if(i == v_odd.size() - 1) {
      odd_list.push_back({cnt, odd_comp});
    }
  }
  cnt = 0;
  int even_comp = v_even.at(0);
  for(int i = 0; i < v_even.size(); ++i) {
    if(even_comp == v_even.at(i)) cnt++;
    else {
      even_list.push_back({cnt, even_comp});
      even_comp = v_even.at(i);
      cnt = 1;
    }
    if(i == v_even.size() - 1) {
      even_list.push_back({cnt, even_comp});
    }
  }

  // for(int i = 0; i < odd_list.size(); ++i) {
  //   cout << odd_list.at(i).first << " : " << odd_list.at(i).second << endl;
  // }
  // for(int i = 0; i < even_list.size(); ++i) {
  //   cout << even_list.at(i).first << " : " << even_list.at(i).second << endl;
  // }

  sort(odd_list.begin(), odd_list.end());
  sort(odd_list.rbegin(), odd_list.rend());
  sort(even_list.begin(), even_list.end());
  sort(even_list.rbegin(), even_list.rend());

  if(odd_list.at(0).second != even_list.at(0).second) {
    cout << ((n / 2) - odd_list.at(0).first) + ((n / 2) - even_list.at(0).first) << endl;
  }
  else {
    if(odd_list.at(0).first < even_list.at(0).first) {
      int odd_min_second = ((n / 2) - odd_list.at(1).first) + ((n / 2) - even_list.at(0).first);
      cout << odd_min_second << endl;;
    }
    else if(odd_list.at(0).first > even_list.at(0).first) {
      int even_min_second = ((n / 2) - odd_list.at(0).first) + ((n / 2) - even_list.at(1).first);
      cout << even_min_second << endl;;
    }
    else {
      if(odd_list.at(0).first == n / 2) {
        cout << n / 2 << endl;
      }
      else {
        cout << min(((n / 2) - odd_list.at(1).first) + ((n / 2) - even_list.at(0).first), ((n / 2) - odd_list.at(0).first) + ((n / 2) - even_list.at(1).first)) << endl;
      }
    }
  }

  return 0;
}
