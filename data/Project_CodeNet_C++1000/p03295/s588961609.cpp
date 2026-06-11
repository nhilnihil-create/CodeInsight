#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;
using Graph = vector<vector<int>>;

struct island{
    int a, b;
};
bool cmp_b(const island &x, const island &y){
    return x.b < y.b;
}

int main(){
    int n, m;
    cin >> n >> m;
    vector<island> Island;
    for(int i=0;i<m;i++){
        int a, b;
        cin >> a >> b;
        island is;
        is.a = a;
        is.b = b;
        Island.push_back(is);
    }
    sort(Island.begin(), Island.end(), cmp_b);
    int ans = 1, b = Island[0].b;
    for(int i=1;i<m;i++){
        if(b <= Island[i].a){
            ans++;
            b = Island[i].b;
        }
    }

    cout << ans << endl;
    return 0;
}