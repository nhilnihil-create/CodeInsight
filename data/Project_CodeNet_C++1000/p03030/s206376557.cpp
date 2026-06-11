#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int n; cin >> n;
    vector<pair<string, pair<int,int> > > sp(n+1);
    string s;
    int p;

    for(int i=1; i<=n; i++){
        cin >> s >> p;
        sp[i].first = s;
        sp[i].second.first = -p;
        sp[i].second.second = i;
    }

    sort(sp.begin(), sp.end());

    for(int i=1; i<=n; i++){
        cout << sp[i].second.second << endl;
    }

    return 0;
}