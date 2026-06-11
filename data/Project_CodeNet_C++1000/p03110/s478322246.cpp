#include <iostream>
#include <vector>
#include <cstdlib>  
#include <algorithm>
#include <string>

using namespace std;
 
int main() {
	long n;cin>>n;
    long og=0;
    double bg = 0;
    for(int i = 0;i<n;i++){
      double x;
      string u;
      cin>>x>>u;
      if(u == "JPY") og += x;
      if(u == "BTC") bg+= x;
    }
    bg = bg*380000.0;
    cout<<og+bg;
    return 0;
}