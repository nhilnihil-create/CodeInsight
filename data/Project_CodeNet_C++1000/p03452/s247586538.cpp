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

const int MAX_N = 100050;
const int MAX_M = 200050;

long long l_in[MAX_M], r_in[MAX_M], d_in[MAX_M];
int N, M;

int par[MAX_N];
long long loc[MAX_N];
long long root_max_dist[MAX_N][2];

//std::pair<long long, long long> par_dist[MAX_N];
/*
std::pair<long long, long long> root_dist (long long x) {
    if (par_dist[x].first == x) {
        return par_dist[x];
    }
    par_dist[x] = root_dist()
}
*/

int root(int x, long long& dist) {
    if (par[x] == x) {
        dist = 0;
        return x;
    }
    par[x] = root(par[x], dist);
    dist += loc[x];
    loc[x] = dist;
    //std::cout << "root:" << x << " " << loc[x] << std::endl;
    
    return par[x]; 
}

bool unite(int x, int y, long long d) {
    //std::cout << "unite:" << x << " " << y << std::endl;
    long long dist;
    int rx = root(x, dist);
    int ry = root(y, dist);
    //std::cout << "check:" << par[1] << " " << loc[1] << std::endl;
    //std::cout << "check:" << y << " " << ry << " " << loc[y] << std::endl;
    //std::cout << loc[1] << " " << loc[2] << " " << loc[3] << std::endl;
    if (rx == ry) {
        //std::cout << x << " " << y << " " << rx << " " << ry << " " << loc[x] << " " << loc[y] << " " << d << std::endl;
        if (loc[y] - loc[x] == d) {
            return true;
        } else {
            return false;
        }
    } else {
        par[rx] = ry;
        loc[rx] = loc[y] - d - loc[x];
        return true;
    }
}

/*
bool same(int x, int y) {
    int rx = root(x);
    int ry = root(y);
    return rx == ry;
}
*/

int main(int argc, char **argv) {
    std::cin >> N >> M;
    for (int i = 1; i <= M; i++) {
        std::cin >> l_in[i] >> r_in[i] >> d_in[i];
    }

    for (int i = 1; i <= N; i++) {
        par[i] = i;
        loc[i] = 0;
        root_max_dist[i][0] = 0;
        root_max_dist[i][1] = 0;
    }

    for (int i = 1; i <= M; i++) {
        if (!unite(l_in[i], r_in[i], d_in[i])) {
            //std::cout << "check" << std::endl;
            std::cout << "No" << std::endl;
            return 0;
        }
    }

    for (int i = 1; i <= N; i++) {
        long long dist;
        const int r = root(i, dist);
        root_max_dist[r][0] = std::min(root_max_dist[r][0], loc[i]);
        root_max_dist[r][1] = std::max(root_max_dist[r][1], loc[i]);
        if (root_max_dist[r][1] - root_max_dist[r][0] > 1000000000) {
            std::cout << "No" << std::endl;
            return 0;
        }
    }

    std::cout << "Yes" << std::endl;
    return 0;

}
