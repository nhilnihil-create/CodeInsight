#include <iostream>
#include <vector>
#include <cstdlib>  
#include <algorithm>
#include <string>

using namespace std;
 
int main() {
    int n,m,x;cin>>n>>m>>x;
    int a[n+1];for(int i = 0;i<n+1;i++){a[i]= 0;}
    for(int i = 0;i<m;i++){
    	int am;cin>>am;
        a[am-1] = 1; 
    }
    int gg = 0;
    int sg = 0;
    for(int i = x;i<n+1;i++){
    	gg += a[i];
    }
    for(int i = 0;i<x;i++){
    	sg+=a[i];
    }
    cout<<min(sg,gg);
    return 0;
}