#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <algorithm>
#include <numeric>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <cmath>
#include <cstring>
#include <unordered_set>
#include <unordered_map>
using namespace std;

#define pb push_back
#define fst first
#define snd second

typedef long long ll;
typedef pair<int,int> pii;
template<typename T> using min_queue=priority_queue<T,vector<T>,greater<T>>;

const ll MOD=1e9+7;

int N;
ll a[10010],b[10010];

int main(){
    ios::sync_with_stdio(0);cin.tie(0);

    cin>>N;
    for(int i=0;i<N;i++) cin>>a[i];
    for(int i=0;i<N;i++) cin>>b[i];

    ll bal=0;
    for(int i=0;i<N;i++) {
      if (a[i]>b[i]) bal-= a[i]-b[i]; else bal += (b[i]-a[i])/2;
    }

    cout << (bal>=0 ? "Yes" : "No") << endl;

    return 0;
}
