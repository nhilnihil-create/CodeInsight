#include <iostream>
#include <vector>
using namespace std;

vector<int> u, v, w;

int makegraph(int l){
    if(l == 1){
        return 1;
    }
    int n = makegraph(l / 2);
    u.push_back(n);
    v.push_back(n + 1);
    w.push_back(0);    u.push_back(n);
    v.push_back(n + 1);
    w.push_back(l / 2);
    if(l % 2 == 1){
        u.push_back(1);
        v.push_back(n + 1);
        w.push_back(l - 1);
    }
    return n + 1;
}

int main()
{
    int l;
    cin >> l;
    int n = makegraph(l);
    int m = v.size();
    cout << n << " " << m << endl;
    for(int i = 0; i < m; i++){
        cout << u[i] << " " << v[i] << " " << w[i] << endl;
    }
}