#include <algorithm>
#include <iostream>
#include <vector>
#include <utility>

using namespace std;

struct Restaurant {
  int id;
  string name;
  int point;

  Restaurant(int i, string n, int p) 
    : id(i), name(n), point(p) {}
  
  bool operator<(const Restaurant& rhs) {
    if (this->name != rhs.name) {
      return this->name < rhs.name;
    } else {
      return this->point > rhs.point;
    }
  }
};

int main() {
  int N;
  cin >> N;

  vector<Restaurant> restaurants;
  restaurants.reserve(N);
  for (int n = 1; n <= N; ++n) {
    string name;
    int point;
    cin >> name >> point;
    restaurants.push_back(Restaurant(n, name, point));
  }
  sort(restaurants.begin(), restaurants.end());
  
  for (const Restaurant& r : restaurants) {
    cout << r.id << endl;
  }
  
  return 0;
}
