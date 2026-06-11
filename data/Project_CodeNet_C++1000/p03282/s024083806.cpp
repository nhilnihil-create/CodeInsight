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
    string s;
    ll k;
    cin >> s >> k;
    for(int i=0;i<k;i++){
        if(s.at(i)!='1'){
            cout << s.at(i) << endl;
            return 0;
        }
        if(i==k-1) cout << 1 << endl;
    }
}