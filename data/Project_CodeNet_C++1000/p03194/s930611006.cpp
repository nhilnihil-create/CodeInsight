#include <iostream>
#include <cstdint>
#include <vector>
#include <cmath>
#include <numeric>
struct unique_factorization_element {
    std::uint32_t prime;
    std::uint8_t pow;
};
//std::ostream& operator<< (std::ostream& os, const unique_factorization_element& e)
//{
//    os << e.prime << '^' << std::uint16_t(e.pow);
//    return os;
//}
std::vector<unique_factorization_element> unique_factorization(std::uint64_t n)
{
    std::vector<unique_factorization_element> re;
    re.reserve(20);
    const std::uint32_t lim = std::sqrt(n);
    auto calc_pow = [&n](std::uint32_t prime){
        std::uint8_t re = 0;
        while(!(n % prime)){
            n /= prime;
            ++re;
        }
        return re;
    };
    if(const auto pow = calc_pow(2)) re.push_back({std::uint32_t(2), pow});
    for(std::uint32_t i = 3; i < lim; i += 2){
        if(const auto pow = calc_pow(i)) re.push_back({i, pow});
    }
    re.shrink_to_fit();
    return re;
}
template <class Container, class T, class BinaryOperation>
T accumulate(Container&& c, T init, BinaryOperation&& binary_op)
{
    return std::accumulate(std::begin(c), std::end(c), init, std::forward<BinaryOperation>(binary_op));
}
int main()
{
    std::uint64_t N, P;
    std::cin >> N >> P;
    if(1 == N){
        std::cout << P << std::endl;
        return 0;
    } else if(1 == P){
        std::cout << '1' << std::endl;
        return 0;
    }
    const auto unique_factorization_elements = unique_factorization(P);
    const auto re = accumulate(unique_factorization_elements, std::uint64_t(1), [N](auto prev, const auto& e){
        const std::uint8_t new_pow = e.pow / N;
        for(std::uint8_t i = 0; i < new_pow; ++i) prev *= e.prime;
        return prev;
    });
    std::cout << re << std::endl;
}