#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct drink {
    long long price;
    long long num;
};
bool comparePrice(struct drink& d1, struct drink& d2) {
    return d1.price < d2.price;
}
int main() {
    long long n, m;
    cin >> n >> m;
    vector<drink> v;
    drink d;
    for (int i=0; i<n; i++) {
        cin >> d.price >> d.num;
        v.push_back(d);
    }
    sort(v.begin(), v.end(), comparePrice);
    long long result = 0;
    auto itr = v.begin();
    while (m > 0) {
        if ((*itr).num < m) {            
            result += (*itr).price * (*itr).num;
            m -= (*itr).num;
        } else {
            result += (*itr).price * m;
            m = 0;
        }
        itr++;
    }
    cout << result << endl;
}