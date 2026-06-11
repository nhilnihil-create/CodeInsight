#include <iostream>
#include <vector>
using namespace std;

struct edge
{
    int l, r, c;
};

int main()
{
    int l;
    cin >> l;
    l--;
    vector<edge> v;
    int k = 1;
    int i = 0;
    while(k * 2 - 1 <= l){
        v.push_back(edge{i, i + 1, 0});
        v.push_back(edge{i, i + 1, k});
        k *= 2;
        i++;
    }
    int t = l - (k - 1);
    int s = k;
    for(int j = 18; j >= 0; j--){
        if((t >> j) & 1){
            v.push_back(edge{j, i, s});
            t -= (1 << j);
            s += (1 << j);
        }
    }
    cout << i + 1 << " " << (int)v.size() << endl;
    for(edge e : v){
        cout << e.l + 1 << " " << e.r + 1 << " " << e.c << endl;
    }
}
