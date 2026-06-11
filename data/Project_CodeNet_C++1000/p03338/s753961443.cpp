#include <iostream>
#include <cstdio>
#include <set>
using namespace std;

int main(){
    int n;
    string s;

    cin >> n >> s;

    int maxv = 0;
    for(int i = 1; i <= n; i++){
        string x, y;
        x = s.substr(0, i);
        y = s.substr(i);
        set<char> set_x;
        set<char> set_y;
        for(int j = 0; j < x.size(); j++){
            set_x.insert(x[j]);
        }
        for(int j = 0; j < y.size(); j++){
            set_y.insert(y[j]);
        }

        set<char>::iterator it;
        int count = 0;
        for(it = set_x.begin(); it != set_x.end(); it++){
            if(set_y.find(*it) != set_y.end()){
                count++;
            }
        }

        maxv = max(maxv, count);
    }

    cout << maxv << endl;

    return 0;
}