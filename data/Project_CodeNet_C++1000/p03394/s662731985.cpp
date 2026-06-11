#include <stdio.h>
#include <vector>
 
typedef long long ll;
using namespace std;

ll gcd(ll a, ll b) {
    if(b == 0) return a;
    return gcd(b,a%b);
}

void solve()
{
    int n;
    scanf("%d", &n);
    if (n == 3) {
        printf("2 5 63\n"); return;
    }
    vector<int> z;
    int i;
    for (i = 1; i < 15000; i++) {
        if (gcd(i, 15000) > 1) {
            z.push_back(i);
            z.push_back(30000 - i);
            if ((int)z.size() >= n-1) break;
        }
    }
    if (n % 2) z.push_back(15000);

    for (i = 0; i < (int)z.size(); i++) {
        printf("%d", z[i]);
        if (i < (int)z.size() - 1) printf(" ");
    }
    printf("\n");

    return;
}

int main(int argc, char* argv[])
{
    solve();

    return 0;
}
