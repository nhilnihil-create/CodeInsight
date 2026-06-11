#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <list>
#include <utility>
#include <tuple>
#include <cstdio>
#include <set>
#include <queue>
#include <stack>
#include <deque>
#include <unordered_map>
#include <unordered_set>
#include <bitset>
#include <cctype>
#include <cmath>
#define _GLIBCXX_DEBUG
using namespace std;
const long long INF = 1LL << 60;
typedef long long ll;
int main() {
    int N,M;
    cin >> N >> M;
    vector<int> data(M,0);
    for(int i=0;i<N;i++){
        int K;
        cin >> K;
        for(int j=0;j<K;j++){
            int A;
            cin >> A;
            data[A-1]++;
        }
    }
    int ans =0;
    for(int i=0;i<M;i++){
        if(data[i]==N){
            ans++;
        }
    }
    cout << ans << endl;
}