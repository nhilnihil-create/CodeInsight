#include <iostream>
#include <array>
int main() {

	int array_value;	
	std::cin >> array_value;
	
	std::array<int, 256> array;
	for(int i = 0; i < array_value; i++) {
		std::cin >> array[i];
	}

	int operation_count = 0;
	while(1) {
	
		for(int ai = 0; ai < array_value; ai++) {
			if((array[ai] % 2) == 0 ){
				array[ai] = array[ai] / 2;
			} else {
				std::cout <<  operation_count << std::endl;
				return 0;
			}
		}
		operation_count++;
	}

	return 0;

}