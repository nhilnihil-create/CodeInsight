#include <iostream>
#include<cmath>
#include<algorithm>
#include<vector>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
#define ll long long
#define ld long double


int main(){

int n;
cin>>n;

vector<int> vec(n+2,0);

int total=0,i=0;
for(i=1;i<=n;i++){
    cin>>vec[i];
    total+=abs(vec[i]-vec[i-1]);
}
total+=abs(vec[i]-vec[i-1]);

for( i=1;i<=n;i++){
    
    cout<<total-(abs(vec[i]-vec[i-1])+ abs(vec[i]-vec[i+1]))+ abs(vec[i+1]-vec[i-1])<<endl;
}
}