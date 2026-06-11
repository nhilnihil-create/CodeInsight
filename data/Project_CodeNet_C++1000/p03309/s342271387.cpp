#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    int64_t total =0;
    cin >>n;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin >> a[i];
        a[i]= a[i] - i-1;
    }

    sort(a.begin(),a.end());

    for(auto &e:a) total += abs(e -a[n/2]);

    cout << total;
   
}