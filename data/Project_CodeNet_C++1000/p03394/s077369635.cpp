#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <iomanip>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <map>
#include <set>
using namespace std;

#define INF (1ll<<60)


long long M = 1000000007;


int main(int argc, char const *argv[]) {
    int n;cin>>n;
    if(n==3){
        cout<<"2 5 63"<<endl;
        return 0;
    }
    int k = n/8, m = n%8;
    for(int i=0;i<k;++i){
        cout<<i*12+2<<" ";
        cout<<i*12+3<<" ";
        cout<<i*12+4<<" ";
        cout<<i*12+6<<" ";
        cout<<i*12+8<<" ";
        cout<<i*12+9<<" ";
        cout<<i*12+10<<" ";
        cout<<i*12+12<<" ";
    }
    map<int, set<int>> ma;
    ma[0] = set<int>();
    ma[1].insert(6);
    ma[2].insert(2);
    ma[2].insert(4);
    ma[3].insert(2);
    ma[3].insert(4);
    ma[3].insert(6);
    ma[4].insert(2);
    ma[4].insert(3);
    ma[4].insert(4);
    ma[4].insert(9);
    ma[5].insert(2);
    ma[5].insert(3);
    ma[5].insert(4);
    ma[5].insert(6);
    ma[5].insert(9);
    ma[6].insert(2);
    ma[6].insert(3);
    ma[6].insert(4);
    ma[6].insert(8);
    ma[6].insert(9);
    ma[6].insert(10);
    ma[7].insert(2);
    ma[7].insert(3);
    ma[7].insert(4);
    ma[7].insert(8);
    ma[7].insert(9);
    ma[7].insert(10);
    ma[7].insert(6);
    for(auto itr=ma[m].begin();itr!=ma[m].end();itr++){
        cout<<*itr + 12*k<<" ";
    }
    cout<<endl;
    return 0;
}