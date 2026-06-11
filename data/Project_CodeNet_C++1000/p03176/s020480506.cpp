#include<bits/stdc++.h>
using namespace std;
int main()
{
  long long int n;
  cin>>n;
  vector<int>h(n);
vector<int>b(n);
map<int,long long>m;

    for(int i=0;i<n;i++){
        cin>>h[i];
    }
    for(int i=0;i<n;i++){
        cin>>b[i];
    }
    for(int i=0;i<n;i++){
 
        int x = h[i];
        long long val = b[i];
        auto itr = m.upper_bound(x);
        if(itr!=m.begin()){
            itr--;
            val += itr->second;
        }
        m[x] = val;
        itr = m.upper_bound(x);
        while(itr != m.end() && itr->second <=val){
            auto temp = itr;
            temp++;
            m.erase(itr);
            itr = temp;
        }
    }
    auto it = m.end();
    it--;
    long long ans  = it->second;
    cout << ans <<"\n";
}