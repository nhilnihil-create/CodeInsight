#include <cstdio>
#include <vector>
#include <cmath>
// D - All Your Paths are Different Lengths

using namespace std;

vector<pair<pair<int,int>,int>> ans;

int main() {
    int N,L,i;

    scanf("%d",&L);

    N = ((int) log2(L)) + 1;
    for (i = 1;i < N;i++) {
        ans.push_back({{i,i + 1},0});
        ans.push_back({{i,i + 1},(1 << (i - 1))});
    }

    for (i = 1;i < N;i++) {
        if (L & 1)
            ans.push_back({{i,N},(L - 1) << (i - 1)});

        L >>= 1;
    }

    printf("%d %d\n",N,ans.size());
    for (pair<pair<int,int>,int> a : ans)
        printf("%d %d %d\n",a.first.first,a.first.second,a.second);

    return 0;
}
