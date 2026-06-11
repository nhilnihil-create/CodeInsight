#include <bits/stdc++.h>
using namespace std;


int main() {

    int64_t n,k;
    cin>>n>>k;

    vector<int64_t> h(n);
    for(int64_t i=0;i<n;i++){
      cin>>h.at(i);
    }

    sort(h.begin(),h.end());

    int64_t diff_min=10000000000;
    for(int i=0;i<n-k+1;i++){
      diff_min=min(diff_min,h.at(i+k-1)-h.at(i));
    }

    cout<<diff_min<<endl;
 

    return 0;
}
