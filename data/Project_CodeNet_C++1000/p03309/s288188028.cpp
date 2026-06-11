#include <bits/stdc++.h>
using namespace std;

int main(){
    
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i=0; i<n; i++){
        cin >> a.at(i);
        a.at(i) = a.at(i)-(i+1);
    }
    sort(a.begin(),a.end());
    long long sum = 0;
    for(int i: a) {
        sum += abs(i - a.at((int)a.size()/2));
    }
    cout << sum << endl;
}
