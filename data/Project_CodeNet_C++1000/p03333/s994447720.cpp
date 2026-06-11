#include <iostream>
#include <algorithm>
#include <utility>
#include <cstdlib>
#include <vector>

class interval {
public:
  int id;
  int begin;
  int end;
  constexpr interval() : id(0), begin(0), end(0) {}
  constexpr interval(const int id, const int begin, const int end) : id(id), begin(begin), end(end) {}
  constexpr int next_position(const int current_position) const {
    return current_position < this->begin ? this->begin : this->end < current_position ? this->end : current_position;
  }
};

int main() {
  int n;
  std::cin >> n;
  std::vector<interval> intervals_order_by_begin_desc(n);
  std::vector<interval> intervals_order_by_end_asc(n);
  for (int i = 0; i < n; ++i) {
    int l, r;
    std::cin >> l >> r;
    intervals_order_by_begin_desc[i] = interval(i, l, r);
    intervals_order_by_end_asc[i] = interval(i, l, r);
  }
  std::sort(intervals_order_by_begin_desc.begin(), intervals_order_by_begin_desc.end(), [](const interval& x, const interval& y){ return x.begin > y.begin; });
  std::sort(intervals_order_by_end_asc.begin(), intervals_order_by_end_asc.end(), [](const interval& x, const interval& y){ return x.end < y.end; });
  const auto calc_distance = [&](const int toggle){
    std::vector<bool> used_intervals(n, false);
    int begins_cursor = 0;
    int ends_cursor = 0;
    int current_position = 0;
    std::uint64_t distance = 0;
    for (int i = 0; i < n; ++i) {
      const interval current_interval = [&](){
        if (i % 2 == toggle) {
          for (; used_intervals[intervals_order_by_begin_desc[begins_cursor].id]; ++begins_cursor);
          return intervals_order_by_begin_desc[begins_cursor];
        } else {
          for (; used_intervals[intervals_order_by_end_asc[ends_cursor].id]; ++ends_cursor);
          return intervals_order_by_end_asc[ends_cursor];
        }
      }();
      const int old_position = current_position;
      current_position = current_interval.next_position(current_position);
      distance += std::abs(current_position - old_position);
      used_intervals[current_interval.id] = true;
#ifdef DEBUG
      std::cout << distance << ": " << old_position << " -> " << current_position << " ([" << current_interval.begin << ", " << current_interval.end << "])" << std::endl;
#endif
    }
    distance += std::abs(current_position);
#ifdef DEBUG
    std::cout << distance << ": " << current_position << " -> " << 0 << " ([0, 0])" << std::endl;
    std::cout << std::endl;
#endif
    return distance;
  };
  std::cout << std::max(calc_distance(0), calc_distance(1)) << std::endl;
  return 0;
}