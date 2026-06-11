#include <stdio.h>
#include <assert.h>
#include <fstream>
#include <iostream>
#include <algorithm>
#include <array>
#include <vector>
#include <queue>
#include <set>
#include <cmath>
#include <map>
#include <unordered_map>
//#include <unordered_set>
//#include <boost/container/static_vector.hpp>
//#include <boost/unordered_set.hpp>
//#include <boost/unordered_map.hpp>
//#include <unistd.h>

//#include <cv.h>
//#include <highgui.h>
#include <stdlib.h>
#include <time.h>

#include <string>

const int MAX_N = 200050;
int H, W, N;
int X[MAX_N], Y[MAX_N];

int possible[MAX_N];

std::set<std::pair<int, int>> st;

int main(int argc, char **argv) {
    std::cin >> H >> W >> N;

    for (int i = 1; i <= N; i++) {
        std::cin >> X[i] >> Y[i];
    }

    for (int i = 1; i <= N; i++) {
        st.insert(std::pair<int, int>({X[i], Y[i]}));
    }

    for (int i = 1; i <= W; i++) {
        possible[i] = H;
    }
    possible[1] = 1;

    int cur_x = 1;
    int cur_y = 1;
    for (int i = 1; i <= H; i++) {
        if (st.find(std::pair<int, int>({i+1, cur_y})) != st.end()) {
            break;
        }
        cur_x++;
        if (st.find(std::pair<int, int>({cur_x, cur_y+1})) == st.end()) {
            cur_y++;
            possible[cur_y] = cur_x;
            //std::cout << "c:" << cur_y << " " << cur_x << std::endl;
        }
    }

    int ret = H;
    for (int i = 1; i <= N; i++) {
        if (X[i] > possible[Y[i]]) {
            ret = std::min(ret, X[i] - 1);
        }
    }

    std::cout << ret << std::endl;
    
    return 0;
}
