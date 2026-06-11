#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

struct Restaurant {
  int id;
  string name;
  int score;
};

vector<int> solve() {
    int n; cin >> n;
    vector<Restaurant> book;
    string s;
    int p;
    for (int i = 1; i <=n; ++i) {
        cin >> s >> p;
        Restaurant r{i, s, p};
        book.emplace_back(r);
    }
    
    sort(book.begin(), book.end(), [](auto r1, auto r2) {
       if (r1.name == r2.name) {
           return r1.score > r2.score;
       } 
       return r1.name < r2.name;
    });
    
    vector<int> res;
    for (auto const& r : book) {
        res.emplace_back(r.id);
    }
    
    return res;
}

int main() {
    vector<int> res = solve();
    for (auto num : res) {
        cout << num << "\n";
    }
}