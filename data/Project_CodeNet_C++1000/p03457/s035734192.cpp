#include <bits/stdc++.h>
using namespace std;

struct Plan {
  int t, x, y;
  Plan operator-(const Plan &other) {
    Plan ret;
    ret.t=t-other.t;
    ret.x=x-other.x;
    ret.y=y-other.y;
    return ret;
  }
};
bool TravelersCheck(Plan dp) {
  int total=abs(dp.x)+abs(dp.y);
  if (dp.t < total) {return false;}
  if (dp.t%2 != total%2) {return false;}
  return true;
}
int main() {
  int N;
  int ti, xi, yi;
  cin >> N;
  unordered_map<int,Plan> travel;
  Plan tmp={0, 0, 0};
  travel[0]=tmp;
  for (int i=1; i<=N; i++) {
    cin >> ti >> xi >> yi;
    Plan tmp={ti ,xi ,yi};
    travel[i]=tmp;
  }
  for (int i=0; i<N; i++) {
    if (TravelersCheck(travel[i+1]-travel[i])) {continue;}
    cout << "No" << endl;
    return 0;
  }
  cout << "Yes" << endl;
}
