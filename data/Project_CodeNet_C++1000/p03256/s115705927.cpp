#include <iostream>
#include <cstdio>
#include <unordered_map>
#include <unordered_set>
#include <string>

using namespace std;


const int N = 2e5 + 10;
int n, m, X, Y;
char col[N];
unordered_map<int, unordered_set<int> > ds[2];
unordered_map<int, int> test[2];
unordered_set<int> checked[2];
unordered_set<int> path[2];

bool walk(int a, int depth) {
    //printf("%d\n", a);
    checked[depth].insert(a);
    if (ds[depth].find(a) == ds[depth].end()) {
        //printf("1 %d\n", a);
        return false;
    }
    int n_d = (depth+1) % 2;
    for(auto itr = ds[depth][a].begin(); itr != ds[depth][a].end(); itr++) {
        //printf("search%d\n", *itr);
        if (path[n_d].find(*itr) != path[n_d].end()) {
            //printf("end");
            return true;
        }
        if (checked[n_d].find(*itr) == checked[n_d].end()) {
            path[n_d].insert(*itr);
            if (walk(*itr, n_d)){
                return true;
            }
            path[n_d].erase(*itr);
        }
    }
    return false;
}

int main() {
    scanf("%d%d", &n, &m);
    scanf("%s", col);
    for (int i = 1, x, y; i <= m; ++i) {
        scanf("%d%d", &x, &y);
        x = x-1;y = y-1;
        X = col[x] == col[y] ? 0 : 1;
        Y = col[x] == col[y] ? 1 : 0;
        //if (ds[X].find(x) == ds[X].end()){
        //    ds[X][x] = {};
        //}
        //if (ds[X].find(y) == ds[X].end()){
        //    ds[X][y] = {};
        //}
        ds[X][x].insert(y);
        ds[X][y].insert(x);
        test[0][x] = y;
        test[0][x] = 4;
    }
    string result = "No";
    for(auto itr = ds[0].begin(); itr != ds[0].end(); itr++) {
        auto isitr = checked[0].find(itr->first);
        //printf("%d\n", itr->first);
        //printf("----------\n", itr->first);
        if (isitr == checked[0].end()){
            path[0].insert(itr->first);
            if (walk(itr->first, 0)) {
                result = "Yes";
            }
            path[0].erase(itr->first);
        }
    }
    printf("%s", result.c_str());
}
