#include <iostream>
#include <vector>
#include <queue>
#include<map>
#include<algorithm>
#include<set>
#define rep(i,n) for(int i = 0;i < n;i++)
#define req(i,n) for(int i = 1; i<=n;i++)
#define ALL(a) a.begin(),a.end()
#define MOD 1000000007
#define B2 100000007
using namespace std;
template<typename A, size_t N, typename T>
void Fill(A(&array)[N], const T & val) {
    std::fill((T*)array, (T*)(array + N), val);
}
typedef long long int ll;
#define P pair<int,int>
int n,a,ans = 0,c,x,y,t;
string s;
int main() {
    cin >> n; int sk = (n % 2) ?  n : n + 1;
    ans = n * (n + 1) / 2 - n / 2;
    vector<P> an;
    req(i, n) {
        for (int j = i + 1; j <= n; j++) {
            if (i + j == sk) continue;
            an.push_back({ i,j });
        }
    }cout << an.size() << endl;
    for (P i : an) cout << i.first << " " << i.second << endl;
}