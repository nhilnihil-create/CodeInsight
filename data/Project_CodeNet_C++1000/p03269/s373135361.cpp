#include <iostream>
#include <algorithm>
#include <vector>
#include <limits.h>
#include <cmath>
#include <map>
#include <iomanip>
using namespace std;
using ll=long long;
using P=pair<int,int>;
int main(){
    int l;
    cin>>l;
    vector<int> e;
    int p=19;
    while(l>0){
       if(l-pow(2,p)>=0){
           e.push_back(p);
           l-=pow(2,p);
       }
       p--;
    }
    int mx=e[0];
    int n=mx+1;
    int m=2*mx+e.size()-1;
    cout<<n<<" "<<m<<endl;
    for(int i=0;i<n-1;i++){
        cout<<i+1<<" "<<i+2<<" "<<0<<endl;
        cout<<i+1<<" "<<i+2<<" "<<pow(2,i)<<endl;
    }
    int now=pow(2,mx)-1;
    for(int i=1;i<e.size();i++){
        cout<<e[i]+1<<" "<<n<<" "<<now+1<<endl;
        now+=pow(2,e[i]);
    }
}