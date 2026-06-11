#define _USE_MATH_DEFINES
#include <iostream>
#include <string>
#include <utility>
#include <stack>
#include <vector>
#include <queue>
#include <algorithm>
#include <map>
#include <climits>
#include <set>
#include <cmath>
#include <numeric>
#include <iomanip>

using namespace std;

vector <pair<pair <int, int>, int > >edges;
void add_base_graph(int msb){
    for(int i = 0; i < msb; i++){
        edges.push_back(make_pair(make_pair(i + 1, i + 2), 0));
        edges.push_back(make_pair(make_pair(i + 1, i + 2), (1 << i)));
    }    
}

int main(){
    int L;
    cin >> L;
    
    int msb = 0;
    for(int i = 20; i >= 0; i--){
        if(((L >> i) & 1) == 1){
            msb = i;
            break;
        }
    }
    
    add_base_graph(msb);
    
    int tmp = (1 << msb);
    for(int i = msb - 1; i >= 0; i--){
        if(((L >> i) & 1) == 1){
            edges.push_back(make_pair(make_pair(i + 1, msb + 1), tmp));
            tmp += (1 << i);
        }
    }
    
    cout << msb + 1 << " " << edges.size() << endl;
    for(int i = 0; i < edges.size(); i++){
        cout << edges[i].first.first << " " << edges[i].first.second << " " << edges[i].second << endl;
    }
    //cout << msb << endl;
    return 0;
}
