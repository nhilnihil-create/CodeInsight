// ABC 100 C: *3 or /2
#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int size; std::cin >> size;
    std::vector<int> sequence(size);
    for (int i=0; i<size; i++) {
        std::cin >> sequence.at(i);
    }

    int counter = 0;
    for (int i=0; i<sequence.size(); i++) {
        int num = sequence.at(i);
        while (true) {
            if (num % 2 != 0) {
                break;
            }
            num /= 2;
            counter++;
        }
    }

    std::cout << counter << "\n";
}