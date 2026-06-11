#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
#define rep(i,n) for(int i=0;i<n;i++)

using namespace std;

int main(){
    int n,a,b;
    int x=0,y=0,z=0;
    cin>>n>>a>>b;
    vector<int> p(n);
    rep(i, n){
        cin>>p[i];
        if (p[i]<=a) x++;
        else if(p[i]>a && p[i]<=b) y++;
        else z++;
    }
    cout<<min({x,y,z})<<endl;
    return 0;
}

