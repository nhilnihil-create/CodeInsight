#include <cstdint>
#include <iostream>
#include <vector>

using namespace std;

class AbsBit
{
public:
    AbsBit(int64_t offset) : bit_(2 * offset + 2, 0), offset_(offset) {}

    void Add(int64_t pos);

    int64_t CountSmaller(int64_t pos) const;

private:
    static int64_t Lsb(int64_t num) { return num & -num; }

    vector<int64_t> bit_;
    int64_t offset_;
};

void AbsBit::Add(int64_t pos)
{
    pos += offset_;
    while (pos < (int64_t)bit_.size()) {
        bit_[pos] += 1;
        pos += Lsb(pos);
    }
}

int64_t AbsBit::CountSmaller(int64_t pos) const
{
    pos += offset_;

    int64_t count = 0;
    while (pos > 0) {
        count += bit_[pos];
        pos -= Lsb(pos);
    }
    return count;
}

int64_t CountBigSubs(int64_t med, const vector<int64_t> &vec)
{
    int64_t balance = 0;
    int64_t subs = 0;
    AbsBit bit(vec.size() + 1);

    bit.Add(0);
    for (const auto &num : vec) {
        balance += (num >= med ? 1 : -1);
        subs += bit.CountSmaller(balance);
        bit.Add(balance);
    }
    return subs;
}

bool SmallEnough(int64_t med, const vector<int64_t> &vec)
{
    int64_t total_subs = 1LL * vec.size() * (vec.size() - 1) / 2 + vec.size();
    int64_t half_subs = (total_subs + 1) / 2;

    return CountBigSubs(med, vec) >= half_subs;
}

int MedianOfMedians(const vector<int64_t> &vec)
{
    int res = 0;
    int pow = (1 << 30);

    while (pow > 0) {
        auto next_res = res + pow;
        pow >>= 1;

        if (SmallEnough(next_res, vec)) {
            res = next_res;
        }
    }
    return res;
}

int main()
{
    int n;
    cin >> n;

    vector<int64_t> vec(n);
    for (auto &num : vec) {
        cin >> num;
    }

    auto res = MedianOfMedians(vec);
    cout << res << "\n";

    return 0;
}
