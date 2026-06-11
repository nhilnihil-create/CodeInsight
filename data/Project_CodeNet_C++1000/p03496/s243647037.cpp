#include<cstdio>
#include<cstdlib>
#include<vector>
using namespace std;
typedef pair<int, int> P;

int n;
int a[50];
vector<pair<int, int>> v;

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    
    int ind = 0;
    for (int i = 0; i < n; i++) {
        ind = (abs(a[i]) > abs(a[ind])) ? i : ind;
    }
    for (int i = 0; i < n; i++) {
        a[i] += a[ind];
        v.push_back(P(ind + 1, i + 1));
    }
    
    if (a[ind] < 0) {
        for (int i = n - 2; i >= 0; i--) {
            if (a[i] > a[i + 1]) {
                a[i] += a[i + 1];
                v.push_back(P(i + 2, i + 1));
            }
        }
    }
    else {
        for (int i = 1; i < n; i++) {
            if (a[i] < a[i - 1]) {
                a[i] += a[i - 1];
                v.push_back(P(i, i + 1));
            }
        }
    }
    
    printf("%d\n", static_cast<int>(v.size()));
    for (auto &i : v) {
        printf("%d %d\n", i.first, i.second);
    }
    return 0;
}