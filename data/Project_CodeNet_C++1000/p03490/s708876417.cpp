#include <iostream>
#include <string>
#include <cstring>
#include <vector>

int arr[2][8008];
int cache[2][8008][8008];

int canGo(int type, int goal, int len) {
    if (len < 0) {
        return (goal == 0) ? 1 : 0;
    }
    int& ret = cache[type][len][goal];
    if (ret != -1) return ret;

    if (canGo(type, abs(goal - arr[type][len]), len - 1)) {
        return ret = 1;
    } else if (canGo(type, abs(goal + arr[type][len]), len - 1)) {
        return ret = 1;
    } else {
        return ret = 0;
    }
}

int main() {
    int tCnt=0, first = 0;
    int cnt[2]; cnt[0] = -1; cnt[1] = 0;
    int x, y;
    memset(cache, -1, sizeof(cache));
    std::string s;
    std::cin >> s;
    std::cin >> x >> y;
    for (int i = 0; i < s.size(); ++i) {
        if (s[i] == 'F') {
            if (tCnt == 0) {
                ++first;
            } else {
                ++arr[tCnt % 2][cnt[tCnt % 2]];
            }
        } else {
            ++cnt[tCnt % 2];
            ++tCnt;
        }
    }
    if (canGo(0, abs(x - first), cnt[0]) && canGo(1, abs(y), cnt[1])) {
        printf("Yes\n");
    } else {
        printf("No\n");
    }

}