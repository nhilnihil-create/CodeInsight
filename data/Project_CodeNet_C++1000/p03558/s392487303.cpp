#include <cstddef>
#include <cstdint>
#include <iostream>
#include <array>

template<class T, std::size_t N>
class static_vector {
	std::array<T, N> data;
	std::size_t size;
public:
	constexpr static_vector() noexcept : data{}, size(0) {}
	constexpr void push_back( T e ) { data.at( size ) = std::move( e ); ++size; }
	constexpr auto begin() noexcept { return data.begin(); }
	constexpr auto end() noexcept { return data.begin() + size; }
};

std::array<static_vector<std::int32_t, 100000>, 54> q;
std::array<bool, 100000> visited;

int main() {
	std::int32_t K;
	std::cin >> K;

	for( int t = 1; t < 10; ++t ) {
		const std::int32_t cost = (K*t) % 10;
		const std::int32_t rem = (K*t) / 10;
		q.at( cost ).push_back( rem );
	}

	for( int i = 0; i <= 45; ++i ) {
		for( auto it = q[i].begin(); it != q[i].end(); ++it ) {
			const std::int32_t r = *it;

			if( r == 0 ) { std::cout << i << std::endl; return 0; }

			if( visited.at( r ) ) { continue; }
			visited.at( r ) = true;

			for( int t = 0; t < 10; ++t ) {
				const std::int32_t cost = (r+K*t) % 10;
				const std::int32_t rem = (r+K*t) / 10;
				q.at( i + cost ).push_back( rem );
			}
		}
	}
}
