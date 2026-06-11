
#include<iostream>

int main() {
	int a, b;
	std::cin >> a >> b;

	bool tab[100][100]{ };// Is a cell(h,w) white ?

	auto p = [&]() {
		for (const auto&e : tab) {

			for (const auto&ee : e)
				std::cout << (ee ? '.' : '#');// cond ? white:black

			std::cout << "\n";
		}
	};
//	p();

	for (auto&e : tab)
		for (auto&ee : e)
			ee = true;

	for (int hi{}; hi < 50; ++hi) {
		for (auto&e : tab[hi])
			e = !e;
	}

//	p();

	--a;
	--b;
	for (int wi{}; wi < 100; wi += 2) {

		for (int hi{}; hi < 49; hi += 2) {
			if (a == 0)
				break;

			auto & here = tab[hi][wi];
			here = !here;
			--a;
		}

		for (int hi{ 51 }; hi<100; hi += 2) {
			if (b == 0)
				break;

			auto& here = tab[hi][wi];
			here = !here;
			--b;
		}
	}

	std::cout << 100 << " " << 100 << "\n";
	p();
	/*for (auto&e : tab) {
		
		for (auto&ee : e)
			std::cout << (ee ? '.' : '#');
		
		std::cout << "\n";
	}*/
	return 0;
}