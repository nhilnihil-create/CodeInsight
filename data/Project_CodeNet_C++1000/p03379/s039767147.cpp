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
    vector<pair<int,int> > x;
    for(int i=0;i<n;i++){
        int y;
        cin >> y;
        x.push_back(make_pair(y,i));
    } 

    sort(x.begin(),x.end());

    vector<int> ans(n,-1);


    for(int i=0;i<n;i++){
        if(i<=n/2-1){
            ans.at(x.at(i).second)=x.at(n/2).first;
        }else{
            ans.at(x.at(i).second)=x.at(n/2-1).first;
        }
    }

    for(int i=0;i<n;i++) cout << ans.at(i) << endl;
}