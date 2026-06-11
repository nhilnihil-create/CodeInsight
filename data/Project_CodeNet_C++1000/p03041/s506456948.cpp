#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define fi first
#define se second
#define pb push_back

const int N = 102;
char s[N];

int main() {
    //ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, k;
    scanf("%d %d\n%s", &n, &k, s);
    k--;
    s[k] -= 'A';
    s[k] += 'a';
    printf("%s", s);
    
    return 0;
}
