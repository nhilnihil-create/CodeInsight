#include <iostream>
#include <sstream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <math.h>
#include <memory>
#include <cctype>
#include <cstring>
#include <vector>
#include <list>
#include <queue>
#include <deque>
#include <stack>
#include <map>
#include <set>
#include <algorithm>
#include <numeric>
#include <iomanip>
#include <unordered_set>
#include <unordered_map>
typedef long long ll;
                                                                            /*,---.   ,--.                          ,--.
                                                                            '   .-'  |  ,---.  ,--.,--. ,--.  ,--. `--'
                                                                            `.  `-.  |  .-.  | |  ||  |  \  `'  /  ,--.
                                                                            .-'    | |  | |  | '  ''  '   \    /   |  |
                                                                            `-----'  `--' `--'  `----'     `--'    `--'*/
using namespace std;
multiset<int> all_val;
vector<int> coord;
vector<int> hight;

int main()
{
    int n;
    cin >> n;
    long long res = 0;
    vector<pair<int, int>> all_pos;
    bool isCor = false;
    for(int i = 0;i<n;i++){
        int a, b;
        cin >> a >> b;
        if(b > a){
            isCor = true;
        }
        all_pos.emplace_back(a,  b);
    }
    if(!isCor){
        cout<<0;
        return 0;
    }
    int mini = 1000000000 + 47;
    long long sum = 0;
    for(int i = 0;i<n;i++){
        sum+=all_pos[i].first;
        if(all_pos[i].second < all_pos[i].first){
            mini = min(mini, all_pos[i].second);
        }
    }
    cout<<sum - mini;

}