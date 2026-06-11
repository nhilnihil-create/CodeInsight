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
    vector<int> x(3);
    cin >> x.at(0) >> x.at(1) >> x.at(2);

    int cnt=0;
    sort(x.begin(),x.end());

    cnt+=x.at(2)-x.at(1);
    if((x.at(2)-(x.at(0)+cnt))%2==1){
        cnt+=(x.at(2)-(x.at(0)+cnt))/2+2;
    }else{
        cnt+=(x.at(2)-(x.at(0)+cnt))/2;
    }

    cout << cnt << endl;
}