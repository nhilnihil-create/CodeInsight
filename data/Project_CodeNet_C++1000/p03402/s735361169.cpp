#include <bits/stdc++.h>
using namespace std;

#define rp(i, k, n) for (int i = k; i < n; i++)
typedef long long ll;

ll mod = 1e9 + 7;
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
const ll inf = 1ll << 60;



int main() {
    int a, b;
    scanf("%d%d", &a, &b);
    vector<vector<int>> upper(50, vector<int>(100, 0));
    vector<vector<int>> lower(50, vector<int>(100, 1));
    int pointer = 0;
    while(pointer < a-1) {
        lower.at((pointer/50) * 2 + 1).at((pointer%50) * 2) = 0;
        pointer ++;
    }
    pointer = 0;
    while(pointer < b-1) {
        upper.at((pointer/50) * 2).at((pointer%50) * 2) = 1;
        pointer ++;
    }
    printf("%d %d\n", 100, 100);
    rp(i, 0, 50) {
        rp(j, 0, 100) {
            if(upper.at(i).at(j) == 0) printf(".");
            else printf("#");
        }
        printf("\n");
    }
    rp(i, 0, 50) {
        rp(j, 0, 100) {
            if(lower.at(i).at(j) == 0) printf(".");
            else printf("#");
        }
        printf("\n");
    }
    
} 