#include <iostream>
#include <vector>
#include <cstdlib>  
#include <algorithm>
#include <string>

using namespace std;
 
int main() {
    int n;cin>>n;
    int v[n];
    int c[n];
    for(int i =0;i<n;i++) cin>>v[i];
    for(int i = 0;i<n;i++) cin>>c[i];
    int vg=0;
    int cg=0;
    for(int i = 0;i<n;i++){
     if(v[i] >= c[i]){
       vg+=v[i];
       cg+=c[i];
     }
    }
    cout<<vg-cg;
    return 0;
}