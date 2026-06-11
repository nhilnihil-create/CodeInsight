#include <iostream>

int main() {
	double DDblRating, DDblGoal;
	double DDblGetPerform;

	std::cin >> DDblRating >> DDblGoal;

	DDblGetPerform = 2 * DDblGoal - DDblRating;

	std::cout << DDblGetPerform << std::endl;
}