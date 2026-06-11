#include <bits/stdc++.h>
using namespace std;


int main() {

    int n;
    cin>>n;

    vector<int> p(n);
    for(int i=0;i<n;i++){
      cin>>p.at(i);
    }

    sort(p.begin(),p.end());

    int64_t sum=0;
    for(int i=0;i<n;i++){
      if(i<n-1)
        sum+=p.at(i);
      else
        sum+=p.at(i)/2;
      
    }

    cout<<sum<<endl;
    
    return 0;
}
