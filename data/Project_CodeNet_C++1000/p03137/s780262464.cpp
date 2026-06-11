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
    vector<int> x;
    for(int i=0;i<m;i++){
        int y;
        cin >> y;
        x.push_back(y);
    }

    sort(x.begin(),x.end());

    //for(int i=0;i<m;i++) cout << x.at(i) << " ";

    if(n>=m){
        cout << 0 << endl;
        return 0;
    }

    vector<int> d;
    for(int i=1;i<m;i++) d.push_back(x.at(i)-x.at(i-1)-1);

    sort(d.begin(),d.end());

    //for(int i=0;i<d.size();i++) cout << d.at(i) << " ";
    //cout << endl;

    int ans=m-n;
    for(int i=0;i<m-n;i++) ans+=d.at(i);

    cout << ans << endl;
}