#include <iostream>
#include <vector>
#include <cstdlib>  
#include <algorithm>
#include <string>

using namespace std;
 
int main() {
    int n,m;cin>>n>>m;
    int x[m];
    for(int i = 0;i<m;i++) cin>>x[i];
    sort(x,x+m);
    int s[m-1];
    for(int i = 0;i<m-1;i++){
      s[i] = x[i+1] -x[i];
    }
    sort(s,s+m-1);
    int g = 0;
    for(int i =0;i<m-1-n+1;i++){
      g+= s[i];
    }
    cout<<g;
    return 0;
}