#include <bits/stdc++.h>
using namespace std;

int main(){
    
    int n;
    cin >> n;
    vector<int> p(n);
    int maxp = 0;
    int sum = 0;
    for(int i=0; i<n; i++){
        cin >> p.at(i);
        sum += p.at(i);
        if(p.at(i) > maxp){
            maxp = p.at(i);
        }
    }
    cout << (sum-maxp) + maxp/2 << endl;
}