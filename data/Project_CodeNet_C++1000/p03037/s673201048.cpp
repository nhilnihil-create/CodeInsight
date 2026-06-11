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
    int n,m;
    cin >> n >> m;
    vector<int> l,r;
    for(int i=0;i<m;i++){
        int s,t;
        cin >> s >> t;
        l.push_back(s);
        r.push_back(t);
    }

    sort(l.begin(),l.end());
    reverse(l.begin(),l.end());

    sort(r.begin(),r.end());

    int ans = r.at(0)-l.at(0)+1;

    if(ans<0){
        cout << 0 << endl;
    }else{
        cout << ans << endl;
    }
}