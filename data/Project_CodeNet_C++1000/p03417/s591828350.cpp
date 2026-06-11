#include<bits/stdc++.h>

template<typename First, typename Second, typename Third>
struct triple {
   First first;
   Second second;
   Third third;
};
using namespace std;

void solve(){
    long long a,b;
    cin>>a>>b;
    if(a==1&&b==1)
       cout<<1;
    
    else if(a==1||b==1)
       cout<<max(0LL,((a*b)-2));
    else 
       cout<<max(0LL,((a-2)*(b-2)));
}
int main(){
    std::ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    solve();
  return 0;
}
