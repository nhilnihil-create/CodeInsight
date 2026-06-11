#include<iostream>
#include<iomanip>
#include<string>
#include<algorithm>
#include<vector>
#include<utility>
#include<tuple>
#include<map>
#include<queue>
#include<stack>
#include<deque>
#include<bitset>
#include<math.h>
using namespace std;
using ll = int64_t;
using Graph = vector<vector<int> >;
const ll M = 1000000007;

int main(){
    int n;
    cin >> n;
    int a[n];
    for(int i=0;i<n;i++) cin >> a[i];

    int cnt=0;
    for(int i=0;i<n;i++){
        while(a[i]%2==0){
            cnt++;
            a[i]/=2;
        }
    }

    cout << cnt << endl;
}