#include <stdio.h>
#include <iostream>

//yy && mm  yy && mm
//yy && mm  yy || mm
//yy mm
//mm yy

bool isYear(int num) {
	return 0 <= num && num <= 99;
}

bool isMonth(int num) {
	return 1 <= num && num <= 12;
}

struct ym {
	int value;
	bool is_year;
	bool is_month;

	ym(int num) {
		value = num;
		is_year = isYear(num);
		is_month = isMonth(num);
	}
};

int main()
{
	int s;
	std::cin >> s;

	int upper_2, lower_2;
	upper_2 = s / 100;
	lower_2 = s - (upper_2 * 100);

	ym upper(upper_2);
	ym lower(lower_2);

	if (upper.is_year && upper.is_month) {
		if (lower.is_year && lower.is_month) {
			std::cout << "AMBIGUOUS" << std::endl;
		}
		else if (lower.is_year) {
			std::cout << "MMYY" << std::endl;
		}
		else if (lower.is_month) {
			std::cout << "YYMM" << std::endl;
		}
		else {
			std::cout << "NA" << std::endl;
		}
	}
	else if (upper.is_year) {
		if (lower.is_month) {
			std::cout << "YYMM" << std::endl;
		}
		else {
			std::cout << "NA" << std::endl;
		}
	}
	else if (upper.is_month) {
		if (lower.is_year) {
			std::cout << "MMYY" << std::endl;
		}
		else {
			std::cout << "NA" << std::endl;
		}
	}
	else {
		std::cout << "NA" << std::endl;
 	}
	return 0;
}