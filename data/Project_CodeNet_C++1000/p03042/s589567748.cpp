// ABC 126 B: YYMM or MMYY
// https://atcoder.jp/contests/abc126/tasks/abc126_b

#include <iostream>
#include <vector>

int main() {
    std::vector<int> sequence(4);
    for (int i=0; i<sequence.size(); i++) {
        char tmp;
        std::cin >> tmp;
        sequence.at(i) = static_cast<int>(tmp-'0');
    }
    int first_part = sequence.at(0)*10 + sequence.at(1);
    int second_part = sequence.at(2)*10 + sequence.at(3);
    if (first_part <= 12 && first_part != 0) {
        if (second_part <= 12 && second_part != 0) {
            std::cout << "AMBIGUOUS" << "\n";
        } else {
            std::cout << "MMYY" << "\n";
        }
    } else {
        if (second_part <= 12 && second_part != 0) {
            std::cout << "YYMM" << "\n";
        } else {
            std::cout << "NA" << "\n";
        }
    }
}