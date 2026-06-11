#include<algorithm>
#include<cstdio>
#include<cstring>
#include<vector>
using namespace std;

const int MAX_S = 1e5;
char s[MAX_S + 1];
vector<int> v;

int main() {
    scanf("%s", s);
    int n = strlen(s);
    int ans = n;
    int a = n / 2;
    for (int i = 1; i < n; i++) {
        if (s[i] != s[i - 1]) {
            v.push_back((i <= a) ? n - i : i); 
        }
    }
    
    sort(v.begin(), v.end());
    printf("%d\n", (v.empty()) ? n : v[0]);
    return 0;
}
