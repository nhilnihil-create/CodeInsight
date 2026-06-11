
#include <iostream>
#include <vector>
#include <set>
#include <functional>

using namespace std;

using LR = pair<long, long>;

using OrderedRanges = multiset<LR, function<bool(const LR &, const LR &)>>;

class Ranges {
    OrderedRanges lefts;
    OrderedRanges rights;

public:
    Ranges(const vector<LR> &ranges) :
        lefts(ranges.begin(), ranges.end(),
              [](const LR &lhs, const LR &rhs) {
                  return lhs.first > rhs.first ||
                      lhs.first == rhs.first && lhs.second > rhs.second;
              }),
        rights(ranges.begin(), ranges.end(),
               [](const LR &lhs, const LR &rhs) {
                   return lhs.second < rhs.second ||
                                       lhs.second == rhs.second &&
                                       lhs.first < rhs.first;
        })
    {}

    LR pop(OrderedRanges &take_from, OrderedRanges &other) {
        auto first = take_from.begin();
        LR ret = *first;
        take_from.erase(first);
        other.erase(other.find(ret));
        return ret;
    }

    LR pop(bool left) {
        return left ? pop(lefts, rights) : pop(rights, lefts);
    }

    // friend ostream &operator<<(ostream &os, const Ranges &ranges);
};

// ostream &operator<<(ostream &os, const Ranges &ranges) {
//     os << ranges.lefts << "," << ranges.rights << endl;
//     return os;
// }

long calc(const vector<LR> &ranges, bool left) {
    Ranges world(ranges);
    long current = 0;
    long ret = 0;
    for(long i=0; i<ranges.size(); i++) {
        // cerr << i << ": " << endl;
        LR pair = world.pop(left);
        // cerr << "popped: " << pair << endl;
        // cerr << "world: " << world << endl;
        if(left) {
            if (current < pair.first) {
                ret += pair.first - current;
                current = pair.first;
            }
        } else {
            if (current > pair.second) {
                ret += current - pair.second;
                current = pair.second;
            }
        }
        left = !left;
    }
    ret += abs(current);
    return ret;
}

int main() {
    long N;
    cin >> N;
    vector<LR> ranges;
    for(long i=0; i<N; i++){
        long l, r;
        cin >> l >> r;
        ranges.push_back(make_pair(l, r));
    }

    //cerr << "start calc v1" << endl;
    long v1 = calc(ranges, true);
    long v2 = calc(ranges, false);

    //cerr << "v1:" << v1 << endl;
    //cerr << "v2:" << v2 << endl;

    cout << max(v1, v2) << endl;
}
