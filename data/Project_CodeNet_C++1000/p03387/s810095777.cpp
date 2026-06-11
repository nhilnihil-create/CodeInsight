#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <cmath>
#include <map>

int main(){
    int a, b, c; std::cin >> a >> b >> c;
    int A = std::min({ a, b, c });
    int C = std::max({ a, b, c });
    int B = a + b + c - A - C;
    if ((A % 2 == 0 && B % 2 == 0 && C % 2 == 0) || (A % 2 == 1 && B % 2 == 1 && C % 2 == 1))
        std::cout << ((C - A) / 2) + ((C - B) / 2) << std::endl;
    else if (A % 2 == 0 && B % 2 == 1 && C % 2 == 0) {
        int count = (C - A) / 2;
        while (true) {
            if (B > C)
                break;
            else {
                B += 2;
                ++count;
            }
        }
        std::cout << count + 1 << std::endl;
    }
    else if (A % 2 == 1 && B % 2 == 0 && C % 2 == 0) {
        int count = (C - B) / 2;
        while (true) {
            if (A > C)
                break;
            else {
                A += 2;
                ++count;
            }
        }
        std::cout << count + 1 << std::endl;
    }
    else if (A % 2 == 1 && B % 2 == 0 && C % 2 == 1) {
        int count = (C - A) / 2;
        while (true) {
            if (B > C)
                break;
            else {
                B += 2;
                ++count;
            }
        }
        std::cout << count + 1 << std::endl;
    }
    else if (A % 2 == 0 && B % 2 == 1 && C % 2 == 1) {
        int count = (C - B) / 2;
        while (true) {
            if (A > C)
                break;
            else {
                A += 2;
                ++count;
            }
        }
        std::cout << count + 1 << std::endl;
    }
    else if (A % 2 == 1 && B % 2 == 1 && C % 2 == 0) {
        int count = (((C - 1) - B) / 2) + ((B - A) / 2);
        std::cout << count + 1 << std::endl;
    }
    else if (A % 2 == 0 && B % 2 == 0 && C % 2 == 1) {
        int count = (((C - 1) - B) / 2) + ((B - A) / 2);
        std::cout << count + 1 << std::endl;
    }
}