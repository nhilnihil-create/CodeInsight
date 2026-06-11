#include <iostream>
#include <vector>
#include <cstdlib>  
#include <algorithm>
#include <string>

using namespace std;
 
int main() {
    int n,q;
    cin>>n>>q;
    string s;
    cin >>s;
    int k[n];
    for(int i = 0;i<n;i++) k[i] = 0;
    for(int i = 0;i<n;i++){
     int aho  =0;
     if(s[i] == 'A'&&s[i+1] == 'C') aho = 1;
     k[i+1] = k[i]+aho;
    }
    for(int i = 0;i<q;i++){
      int l,r;cin>>l>>r;
      cout<<k[r-1]-k[l-1]<<endl;
    }
    return 0;
}