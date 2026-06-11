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
#include <unordered_set>
//#include <boost/container/static_vector.hpp>
//#include <boost/unordered_set.hpp>
//#include <boost/unordered_map.hpp>
//#include <unistd.h>

//#include <cv.h>
//#include <highgui.h>
#include <stdlib.h>
#include <time.h>

#include <string>

struct Node {
    std::vector<int> edge;
    bool is_searched;
};

const int MAX_N = 200050;
std::string s_in;
char s[MAX_N];
int N, M;
int a[MAX_N], b[MAX_N];

Node graph[MAX_N];
std::unordered_set<int> us;

bool can_loop(int i, int from) {
    if (from == -1 || s[i] != s[from]) {
        if (us.find(i) != us.end()) {
            return true;
        } else {
            us.insert(i);
            graph[i].is_searched = true;
        }
    }
    for (int next : graph[i].edge) {
        if (from == -1 || s[i] != s[from]) {
            if (s[next] == s[i] && can_loop(next, i)) {
                return true;
            } 
        } else {
            if (s[next] != s[i] && can_loop(next, i)) {
                return true;
            }
        }
    }
    if (from == -1 || s[i] != s[from]) {
        us.erase(i);
    }

    return false;

}

int main(int argc, char **argv) {
    std::cin >> N >> M;
    std::cin >> s_in;

    for (int i = 1; i <= M; i++) {
        std::cin >> a[i] >> b[i];
    }

    for (int i = 0; i < s_in.size(); i++) {
        s[i+1] = s_in[i];
    }

    for (int i = 1; i <= M; i++) {
        graph[a[i]].edge.push_back(b[i]);
        graph[b[i]].edge.push_back(a[i]);
    }

    for (int i = 1; i <= N; i++) {
        graph[i].is_searched = false;
    }

    for (int i = 1; i <= N; i++) {
        //std::cout << "check0:" << i << std::endl;
        if (!graph[i].is_searched && can_loop(i, -1)) {
            std::cout << "Yes" << std::endl;
            return 0;
        }
    }
    
    std::cout << "No" << std::endl;
    return 0;
}