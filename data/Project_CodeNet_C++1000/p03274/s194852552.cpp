#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,k;
    cin >> n >> k;
    vector<int> x(n);
    for(int i=0; i<n; i++){
        cin >> x.at(i);
    }
    int comp = INT_MAX;
    int sum = 0;
    for(int i=0; i<=n-k; i++){
        
        if(abs(x.at(i+k-1)) + abs(x.at(i)-x.at(i+k-1)) < abs(x.at(i)) + abs(x.at(i)-x.at(i+k-1)) ){
            sum = abs(x.at(i+k-1)) + abs(x.at(i)-x.at(i+k-1));
        }else{
            sum = abs(x.at(i)) + abs(x.at(i)-x.at(i+k-1));
        }
        if(comp > sum){
            comp = sum;
        }
        sum = 0;
    }
    cout << comp << endl;
}