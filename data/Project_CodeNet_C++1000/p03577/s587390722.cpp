#include <cmath>
#include <cstdlib>
#include <iostream>
#include <bitset>
#include <deque>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <vector>
#include <algorithm>
#include <iterator>
#include <string>
#include <chrono>
#include <random>
#include <tuple>
#include <utility>
#include <fstream>

const long INF = (1l << 30);
const long LINF = (1l << 60);

std::string s;

int main(){
    std::cin >> s;
    std::cout << s.substr(0, s.length() - 8) << std::endl;
}
