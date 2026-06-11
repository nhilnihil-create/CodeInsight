#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <math.h>
#include <algorithm>
#include <deque>
#include <queue>
#include <climits>
#include <set>
using namespace std;
#define ll long long
#define ull unsigned long long
#define ve vector
#define umap unordered_map
#define iter iterator
int n,k, x=1;

void solve() {
    cin>>n>>k;
    for(int i=0;i<n;i++) {
        if(x <= k) x *= 2;
        else x += k;
    }
    cout<<x<<endl;
}

int main() {
    solve();
    return 0;
}