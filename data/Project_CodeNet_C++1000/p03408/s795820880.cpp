#include<iostream>
#include<string>
#include<utility>
#include<map>
#include<algorithm>
#include<cstdio>
#define Fast ios_base :: sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;
int main() {
    Fast;
    int n, m;
    cin >> n;
    map<string, int> blue, red;
    int i;
    string s;
    for(i=0; i<n; i++){
        cin >> s;
        blue[s]++;
        //red[s] = 0;
    }
    cin >> m;
    for(i=0; i<m; i++){
        cin >> s;
        red[s]++;
        //if()
    }
    int count = 0;
    for(auto it=blue.begin(); it!=blue.end(); it++){
        //count = max(count, blue[i].second - red[i].second);
        //cout << it->first << " " << it->second << endl;
        //cout << red[it->first] << endl;
        //int tmp =
        count = max(count, it->second-red[it->first]);
    }
    cout << count << endl;
    return 0;
}