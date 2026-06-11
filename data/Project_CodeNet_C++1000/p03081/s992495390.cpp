#include <fstream>
#include <iostream>
#include <string>

using namespace std;

int N, M, solst, soldr;
string s;
struct spell {
    char c, d;
} a[200005];

bool Check(int poz, bool dir) {
    int i;
    for (i = 1; i <= M; i++) {
        if (a[i].c == s[poz]) {
            if (a[i].d == 'R')poz++;
            else poz--;
        }
        if (poz < 0 && dir == 0) return true;
        else if (poz >= N && dir == 0) return false;
        if (poz >= N && dir == 1)return true;
        else if (poz < 0 && dir == 1)return false;
    }
    return false;
}

void CautBin(int st, int dr, bool dir) {
    int mid = (st + dr) / 2;
    if (st == dr && dir == 0 && Check(mid, dir) == 1)solst = mid;
    else if (st == dr && dir == 0 && Check(mid, dir) == 0) solst = -1;
    else if (st == dr && dir == 1 && Check(mid, dir) == 1) soldr = mid;
    else if (st == dr && dir == 1 && Check(mid, dir) == 0) soldr = N;

    else {
        if (dir == 0 && Check(mid + 1, dir) == 0)CautBin(st, mid, dir);
        else if (dir == 0)CautBin(mid + 1, dr, dir);
        if (dir == 1 && Check(mid, dir) == 0)CautBin(mid+1, dr, dir);
        else if (dir == 1)CautBin(st, mid, dir);
    }
}


int main() {
    int i;
    cin >> N >> M;
    cin >> s;
    for (i = 1; i <= M; i++) {
        cin >> a[i].c >> a[i].d;
    }
    CautBin(0, N - 1, false);
    CautBin(0, N - 1, true);
    cout << soldr - solst - 1;
    return 0;
}