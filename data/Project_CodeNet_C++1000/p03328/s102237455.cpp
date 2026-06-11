#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
#include<queue>
#include<map>
#include<math.h>
#include<string>
#include <cctype>
#include <cstdlib>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define reps(i, s, n) for (int i = s; i < (int)(n); i++)
#define out(x) cout << x << endl
#define INF 1ll<<60;

using namespace std;
using ll = long long;
typedef pair<int, int> P;

int main(){
    int a, b;
    cin >> a >> b;
    int s[1000];

    int count=0;
    for(int i=1; i<=999; i++){
        count+=i;
        s[i-1] = count;
    }
    
    out(s[b-a-1]-b);
}