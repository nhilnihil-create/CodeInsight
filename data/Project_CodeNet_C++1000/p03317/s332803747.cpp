#include <bits/stdc++.h>
using namespace std;
const int INF = 2147483647;
using ll = long long;

int main(){
    double n;
    double k;
    cin >> n >> k;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin >> a.at(i);
    }
    double one_pos ;
    for(int i=0;i<n;i++){
        if(a.at(i)==1) one_pos = i; 
    }
    cout << ceil((n-1)/(k-1)) << "\n";
    return 0;
}