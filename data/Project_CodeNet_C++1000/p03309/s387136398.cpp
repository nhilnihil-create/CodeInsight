#include <bits/stdc++.h>
using namespace std;
using ll = long long;
vector<int>s;

int main() {
    int n;
    cin>>n;ll p=0;
   for(int i=1;i<=n;i++){
    ll temp;
    cin>>temp;
    ll k = (temp-i);
   s.push_back(k);
   }
   sort(s.begin(),s.end());
    ll med = s[(n-1)/2];
    //cout<<med<<endl;
    for(auto x:s){
           // cout<<x<<endl;
        p+=abs(x-med);
    }
cout<<p;
 return 0;
}
