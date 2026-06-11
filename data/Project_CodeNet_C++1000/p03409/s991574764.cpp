#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef pair<int, int> P;

bool cmp(P a, P b){
    if(a.first == b.first) return a.second < b.second;
    return a.first < b.first;
}

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    vector<P> red, blue;
    for(int i=0; i<n; i++){
        int a, b;
        cin >> a >> b;
        red.push_back(make_pair(a, b));
    }
    for(int i=0; i<n; i++){
        int a, b;
        cin >> a >> b;
        blue.push_back(make_pair(a, b));
    }
    sort(red.begin(), red.end(), cmp);
    sort(blue.begin(), blue.end(), cmp);

    int cnt = 0;
    for(P b : blue){
        auto ub = upper_bound(red.begin(), red.end(), b, cmp);
        auto max_i = red.end();
        int max_y = -1;
        for(auto itr = red.begin(); itr != ub; itr++){
            if(itr->second < b.second && itr->second >= max_y){
                max_y = itr->second;
                max_i = itr;
            }
        }
        if(max_i != red.end()){
            cnt++;
            red.erase(max_i);
        }
    }
    cout << cnt << endl;
    return 0;
}
