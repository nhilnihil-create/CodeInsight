#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>

using namespace std;

template <class It> string join(It i1, It i2)
{
    ostringstream ss;
    for (auto it = i1; it != i2; ++it)
        ss << ((it == i1) ? "" : ", ") << (*it);
    return ss.str();
}

void Print() { cout << endl; }
template <class Head, class... Args> void Print(Head &&head, Args&&... args)
{
    cout << head;
    Print(args...);
}

#ifdef DEBUG
#define Dump(x) cerr << #x << " = " << x << endl;
#define Dumps(x) cerr << #x << " : { " << join(x.begin(), x.end()) << " }" << endl;
#else
#define Dump(x)
#define Dumps(x)
#endif

using ull_t = unsigned long long;

int main()
{
    string s;
    cin >> s;

    const size_t N = s.size();
    constexpr ull_t K = 1e9 + 7;
    ull_t n_abc(0), n_bc(0), n_c(0), var(1);

    auto add = [&K](ull_t &x, ull_t y) { x = (x + y) % K; };
    
    for (int i = 1; i <= N; ++i)
    {
        char ch = s.at(N - i);

        switch (ch)
        {
        case '?':
            add(n_abc, (n_abc * 2 + n_bc));
            add(n_bc, (n_bc * 2 + n_c));
            add(n_c, (n_c * 2 + var));
            var = (var * 3) % K;
            break;
        case 'A':
            add(n_abc, n_bc);
            break;
        case 'B':
            add(n_bc, n_c);
            break;
        case 'C':
            add(n_c, var);
            break;
        }
#ifdef DEBUG        
        Print("ch = ", ch, ", ABC = ", n_abc, ", BC = ", n_bc, ", C = ", n_c);
#endif
    }

    cout << n_abc << endl;
}
