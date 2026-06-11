#include <iostream>
#include <cstring>
#include <cmath>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <set>
#include <map>
#include <iterator>
#include <stack>
#include <string.h>
#include <cstdlib>
#include <queue>
#include <list>
#include <string>
#include <functional>
#include <sstream>

using namespace std;

int main()
{
    int N,M;
    int x,y;
    vector<pair<int,int>> v;
    
    cin >> N >> M;
    for (int i = 0;i < M;i++){
        cin >> x >> y;
        x--;
        y--;
        v.push_back(make_pair(y,x));
    }
    sort(v.begin(),v.end());
    
    int res = 1;
    int sta = v[0].first;
    
    for (int i = 1;i < v.size();i++){
        if (v[i].second >= sta){
            res++;
            sta = v[i].first;
        }
    }
    
    cout << res << endl;
}
