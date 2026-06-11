#include <string>
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cmath>
using namespace std;

typedef long long ll;

#define CPP_STR(x) CPP_STR_I(x)
#define CPP_CAT(x,y) CPP_CAT_I(x,y)
#define CPP_STR_I(args...) #args
#define CPP_CAT_I(x,y) x ## y

#define FOR(i, start, end) for(ll i = (start), CPP_CAT(i,xxxx_end)=(end); i < CPP_CAT(i,xxxx_end); ++i)
#define REP(i, n) FOR(i, 0, n)

int h;
int N;

int search(string str) {
    int cnt = 0;
    bool isValid = str.find('7') != string::npos &&
                   str.find('5') != string::npos &&
                   str.find('3') != string::npos &&
                   stoi(str) <= N;

    if (isValid) {
        cnt++;
    }
    if (str.size() == h) {
        return cnt;
    }

    cnt += search(str + "7");
    cnt += search(str + "5");
    cnt += search(str + "3");

    return cnt;
}

int main(void) {
    cin >> N;
    h = to_string(N).size();

    string buf;
    int ans = search(buf);
    cout << ans << endl;

    return 0;
}