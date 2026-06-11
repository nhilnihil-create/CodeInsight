#include <iostream>
#include <algorithm>
#include <string>
#include <cmath>

using namespace std;

int main(){
    int n,m,l,r,min=100000,max=0;
    cin>>n>>m;
    for(int i=0;i<m;i++){
        cin>>l>>r;
        if(min>r)min=r;
        if(max<l)max=l;
    }
    if(max<=min)cout<<min-max+1<<"\n";
    else cout<<0<<"\n";
}