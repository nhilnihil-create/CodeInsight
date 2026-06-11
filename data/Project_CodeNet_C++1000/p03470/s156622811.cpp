#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr.at(i);
    sort (arr.begin(),arr.end(),greater<int>());
     int prev = arr.at(0);
     int ans = 1;
     for (int i = 1; i < n; i++){
         if(prev != arr.at(i))ans++;
         prev = arr.at(i);   
     }
     cout << ans <<endl;
}