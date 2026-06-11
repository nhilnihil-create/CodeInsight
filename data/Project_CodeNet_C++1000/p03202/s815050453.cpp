#include <iostream>
#include <vector>
#include <stack>

using namespace std;

struct Counter
{
    int radix;
    vector<int> value;
    vector<int> index;

    Counter(int radix)
    {
        this->radix = radix;
        value.push_back(0);
        index.push_back(0);
    }

    void add(int b)
    {
        if (b > index.back())
        {
            index.push_back(b);
            value.push_back(0);
            return;
        }
        while (b < index.back())
        {
            index.pop_back();
            value.pop_back();
        }
        if (index.back() != b)
        {
            index.push_back(b);
            value.push_back(0);
        }
        inc();
    }

    void inc()
    {
        if (radix == 1)
        {
            value[0]++;
            return;
        }

        while (++value.back() == radix && value.size() > 1)
        {
            int carried_base = index.back();
            index.pop_back();
            value.pop_back();

            if (carried_base - 1 != index.back())
            {
                index.push_back(carried_base - 1);
                value.push_back(0);
            }
        }
    }

    bool is_valid() const
    {
        return value[0] == 0;
    }
};

int main()
{
    int n;
    cin >> n;

    vector<int> a(n);
    for (int &v : a)
    {
        cin >> v;
    }

    auto ok = [&a](int mid) {
        Counter counter(mid);
        for (int v : a)
        {
            counter.add(v);
        }
        return counter.is_valid();
    };

    int low = 0, high = n;
    while (high - low > 1)
    {
        int mid = (low + high) / 2;

        (ok(mid) ? high : low) = mid;
    }

    cout << high << endl;

    return 0;
}
