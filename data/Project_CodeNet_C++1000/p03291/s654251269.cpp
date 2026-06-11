#include <cstdint>
#include <iostream>
#include <vector>

template <std::size_t MOD> class ModuloInteger
{
public:
    ModuloInteger(const std::size_t init)
        : value(init)
    {
    }

    ModuloInteger operator+(const ModuloInteger& value);
    void operator+=(const ModuloInteger& value);

    ModuloInteger operator-(const ModuloInteger& value);
    void operator-=(const ModuloInteger& value);

    ModuloInteger operator*(const ModuloInteger& value);
    void operator*=(const ModuloInteger& value);

    ModuloInteger operator+(const size_t value);
    void operator+=(const size_t value);

    ModuloInteger operator-(const size_t value);
    void operator-=(const size_t value);

    ModuloInteger operator*(const size_t value);
    void operator*=(const size_t value);

    std::size_t value;
};

template <std::size_t MOD> ModuloInteger<MOD> ModuloInteger<MOD>::operator+(const ModuloInteger& value)
{
    return (this->value + value.value) % MOD;
}

template <std::size_t MOD> void ModuloInteger<MOD>::operator+=(const ModuloInteger& value)
{
    this->value = (this->value + value.value) % MOD;
}

template <std::size_t MOD> ModuloInteger<MOD> ModuloInteger<MOD>::operator-(const ModuloInteger& value)
{
    return (this->value + MOD - value.value) % MOD;
}

template <std::size_t MOD> void ModuloInteger<MOD>::operator-=(const ModuloInteger& value)
{
    this->value = (this->value - value.value) % MOD;
}

template <std::size_t MOD> ModuloInteger<MOD> ModuloInteger<MOD>::operator*(const ModuloInteger& value)
{
    return (this->value * value.value) % MOD;
}

template <std::size_t MOD> void ModuloInteger<MOD>::operator*=(const ModuloInteger& value)
{
    this->value = (this->value * value.value) % MOD;
}

template <std::size_t MOD> ModuloInteger<MOD> ModuloInteger<MOD>::operator+(const size_t value)
{
    return (this->value + value) % MOD;
}

template <std::size_t MOD> void ModuloInteger<MOD>::operator+=(const size_t value)
{
    this->value = (this->value + value) % MOD;
}

template <std::size_t MOD> ModuloInteger<MOD> ModuloInteger<MOD>::operator-(const size_t value)
{
    return (this->value + MOD - value) % MOD;
}

template <std::size_t MOD> void ModuloInteger<MOD>::operator-=(const size_t value)
{
    this->value = (this->value - value) % MOD;
}

template <std::size_t MOD> ModuloInteger<MOD> ModuloInteger<MOD>::operator*(const size_t value)
{
    return (this->value * value) % MOD;
}

template <std::size_t MOD> void ModuloInteger<MOD>::operator*=(const size_t value)
{
    this->value = (this->value * value) % MOD;
}

using namespace std;

using modint = ModuloInteger<1000000007>;

void solve1(vector<vector<modint>>& dp, const string& s)
{
    dp[0][0] = 1;
    for (int i = 1; i <= s.size(); ++i)
    {
        for (int j = 0; j <= 3; ++j)
        {
            dp[j][i] = dp[j][i - 1] * (s[i - 1] == '?' ? 3 : 1);
        }
        if (s[i - 1] == 'A' || s[i - 1] == '?')
            dp[1][i] += dp[0][i - 1];
        if (s[i - 1] == 'B' || s[i - 1] == '?')
            dp[2][i] += dp[1][i - 1];
        if (s[i - 1] == 'C' || s[i - 1] == '?')
            dp[3][i] += dp[2][i - 1];
    }
}

int main()
{
    string s;
    cin >> s;

    vector<vector<modint>> dp(5, vector<modint>(s.size() + 1, 0));

    solve1(dp, s);

    cout << dp[3][s.size()].value << endl;
}