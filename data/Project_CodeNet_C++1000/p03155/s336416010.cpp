#include <iostream>
#include <algorithm>
#include <set>
#include <functional>
#include <list>
#include <bitset>
#include <numeric>
#include <utility>
#include <cmath>
#include <vector>
#include <queue>
#include <string>
#include <map>

#define INF 1e9
#define MOD 1000000007
#define ll long long
using namespace std;
int dx[4]={1,0,-1,0},dy[4]={0,1,0,-1};
typedef unsigned long long ull;
typedef pair<int, int> pr;


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,h,w;
    cin>>n>>h>>w;
    cout<<(n-h+1)*(n-w+1)<<endl;
    // vector<int>a={1,2,3,4,5,6};
    // rotate(a.rbegin(), a.rbegin()+1, a.rend());
    // for(auto &itr:a){
    //     cout<<itr<<" ";
    // }
    // rotate(a.rbegin(), a.rbegin()+1, a.rend());
    // cout<<endl;
    // for(auto &itr:a){
    //     cout<<itr<<" ";
    // }
    // cout<<endl;
    return 0;
}