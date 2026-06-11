#include <iostream>
#include <vector>

class EratosthenesSieve {
private:
    std::vector<bool> prime;

    void build(int N)
    {
        prime.assign(N, true);
        prime[0] = prime[1] = false;
        for (int i = 2; i * i < N; i++)
            if (prime[i])
                for (int j = i * 2; j < N; j += i)
                    prime[j] = false;
    }

public:
    EratosthenesSieve(int N)
    {
        build(N);
    }

    bool is_prime(int x)
    {
        return prime.at(x);
    }
};

int main()
{
    const int N = 114514;
    EratosthenesSieve es(N);
    std::vector<int> x(N);
    for (int i = 1; i < N; i += 2)
        if (es.is_prime(i) && es.is_prime((i + 1) / 2))
            x[i] = 1;

    for (int i = 1; i < N; i++)
        x[i] += x[i - 1];

    int Q;
    std::cin >> Q;
    for (int i = 0; i < Q; i++) {
        int l, r;
        std::cin >> l >> r;
        std::cout << x[r] - x[l - 1] << std::endl;
    }
    return 0;
}