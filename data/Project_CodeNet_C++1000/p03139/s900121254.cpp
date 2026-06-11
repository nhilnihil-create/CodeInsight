#include <iostream>
#include <algorithm>
#include <vector>
template <typename Base>
class SparseTable
{
public:
    using T = typename Base::T;
    using SemiLattice = Base;
    template <typename InIt>
    SparseTable(const InIt first, const InIt last) : size(std::distance(first, last)), lg2(size + 1, 0)
    {
        std::vector<T> val{first, last};
        for (std::size_t i = 2; i <= size; i++) { lg2[i] = lg2[i / 2] + 1; }
        table.resize(size, std::vector<T>(lg2[size] + 1));
        for (std::size_t i = 0; i < size; i++) { table[i][0] = val[i]; }
        for (std::size_t j = 0; j < lg2[size]; j++) {
            for (std::size_t i = 0, w = 1 << j; i <= size - (w << 1); i++) { table[i][j + 1] = op(table[i][j], table[i + w][j]); }
        }
    }
    T accumulate(const std::size_t l, const std::size_t r) const
    {
        const std::size_t j = lg2[r - l];
        return op(table[l][j], table[r - (1 << j)][j]);
    }

private:
    const std::size_t size;
    std::vector<std::size_t> lg2;
    std::vector<std::vector<T>> table;
    const SemiLattice op{};
};
int main()
{
    int N, A, B;
    std::cin >> N >> A >> B;
    std::cout << std::min(A, B) << " " << std::max(0, A + B - N) << std::endl;
    return 0;
}