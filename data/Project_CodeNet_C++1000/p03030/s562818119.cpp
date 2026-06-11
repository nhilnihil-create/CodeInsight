#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<tuple<string, int, int>> sp(n);
    for(int i = 0;i < n;i++){
        string a;
        int b;
         cin >> a >> b;
         sp.at(i) = make_tuple(a, 100 - b, i+1);
    }

    sort(sp.begin(), sp.end());

    for(int i = 0;i < n;i++){
        int num;
        tie(ignore, ignore, num) = sp.at(i);
        cout << num << endl;
    }

    
}