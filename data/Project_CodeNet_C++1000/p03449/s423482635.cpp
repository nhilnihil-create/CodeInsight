#include <iostream>
#include<cmath>
#include<algorithm>
#include<vector>
using namespace std;
#define ll long long
#define ld long double


int main(){

int n;
cin>>n;
vector<vector<int>> vec(2,vector<int>(n+1,0));
for(int i=1;i<=n;i++){
    cin>>vec[0][i];
}
for(int i=1;i<=n;i++){
    cin>>vec[1][i];
}
for(int i=1;i<=n;i++){
    vec[0][i]+=vec[0][i-1];
 //   cout<<vec[0][i]<<" "<<vec[1][i]<<" ";
    vec[1][i]=vec[1][i] + max(vec[0][i],vec[1][i-1]);
  //  cout<<vec[1][i]<<" "<<endl;
    
}
cout<<vec[1][n];
}