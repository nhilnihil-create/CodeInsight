#include <iostream>
#include<algorithm>
#include<cmath>
#include<vector>
#include<set>
#include<map>
using namespace std;
int main(void){
   
int n,k;
cin>>n>>k;

int ans=1;
while(n--){
    
    ans= min(ans*2, ans+k);
}
  cout<<ans; 
    
}
