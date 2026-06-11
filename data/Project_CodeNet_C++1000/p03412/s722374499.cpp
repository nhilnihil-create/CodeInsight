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
//#include <unordered_map>
//#include <unordered_set>
//#include <boost/container/static_vector.hpp>
//#include <boost/unordered_set.hpp>
//#include <boost/unordered_map.hpp>
//#include <unistd.h>

//#include <cv.h>
//#include <highgui.h>
#include <stdlib.h>
#include <string>

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
//#include <unordered_map>
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
int N;
long long a_in[MAX_N], b_in[MAX_N];

int ret_bit[40];

int main(int argc, char **argv) {
    std::cin >> N;
    for (int i = 1; i <= N; i++) {
        std::cin >> a_in[i];
    }
    for (int i = 1; i <= N; i++) {
        std::cin >> b_in[i];
    }

    long long tmp_mask = 0;
    for (int k = 0; k <= 30; k++) {
        tmp_mask += (1 << k);
        std::vector<long long> a, b;
        for (int i = 1; i <= N; i++) {
            a.push_back(a_in[i] & tmp_mask);
            b.push_back(b_in[i] & tmp_mask);
        }
        std::sort(a.begin(), a.end());
        std::sort(b.begin(), b.end());
        long long border01 = N - 1;
        long long border10 = N - 1;
        long long border11 = N - 1;
        long long cond11 = (1 << (k + 1)) + (1 << k);
        long long cond10 = (1 << (k + 1));
        long long cond01 = (1 << k);

        long long tmp = 0;
        for (int i = 0; i < a.size(); i++) {
            while (0 <= border11 && cond11 <= a[i] + b[border11]) {
                border11--;
            }
            while (0 <= border10 && cond10 <= a[i] + b[border10]) {
                border10--;
            }
            while (0 <= border01 && cond01 <= a[i] + b[border01]) {
                border01--;
            }
            tmp += N - 1 - border11;
            tmp += border10 - border01;
        }
        ret_bit[k] = tmp % 2;
    }

    long long ret = 0;
    for (int k = 0; k <= 30; k++) {
        if (ret_bit[k] == 1) {
            ret += (1 << k);
        }
    }

    std::cout << ret << std::endl;
    
    return 0;

}

