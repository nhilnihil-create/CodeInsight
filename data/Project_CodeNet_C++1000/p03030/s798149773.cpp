#include <bits/stdc++.h> 
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<tuple<string, int,int>> data(n);
    for (int i = 0; i < n; i++){
        string a;
        int b;
        cin >> a >> b;
        data.at(i) = make_tuple(a,-1*b,i+1);
    }
    sort(data.begin(), data.end());
    for (int i = 0; i < n; i++){
        cout << get<2>(data.at(i)) << endl;
    }
}
