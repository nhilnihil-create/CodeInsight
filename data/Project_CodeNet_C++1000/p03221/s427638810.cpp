#include <algorithm>
#include <cstdint>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct City {
  City(int64_t i, int64_t p, int64_t y, int64_t n)
    : id(i), p(p), year(y), no(n) {}
  int64_t id;
  int64_t p;
  int64_t year;
  int64_t no;
};

string Output(int64_t n) {
  string str = to_string(n);
  string pref = "";
  for (size_t i = str.size(); i < 6; ++i) {
    pref += '0';
  }
  return pref + str;
}

int main() {
  int64_t N, M;
  cin >> N >> M;

  vector<City> cities;
  cities.reserve(M);
  for (int64_t m = 0; m < M; ++m) {
    int64_t P, Y;
    cin >> P >> Y;
    cities.emplace_back(m, P, Y, 0);
  }
  sort(cities.begin(), cities.end(),
       [] (const City& lhs, const City& rhs) {
         if (lhs.p != rhs.p) {
           return lhs.p < rhs.p;
         }
         return lhs.year < rhs.year;
       });
  int64_t no = 1;
  int64_t cur_p = 0;
  for (City& city : cities) {
    if (cur_p != city.p) {
      no = 1; cur_p = city.p;
    }
    city.no = no++;
  }
  sort(cities.begin(), cities.end(),
       [] (const City& lhs, const City& rhs) {
         return lhs.id < rhs.id;
       });
  for (const City& city : cities) {
    cout << Output(city.p) << Output(city.no) << endl;
  }

  return 0;
}
