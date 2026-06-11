#include <iostream>
#include<cmath>
#include<algorithm>
#include<vector>
using namespace std;
#define ll long long
#define ld long double

int main(void){
int n;
cin>>n;
vector<int> vec(n);
for(int i=0;i<n;i++){
    cin>>vec[i];
}

sort(vec.begin(),vec.end(), greater<int>());

int ans=1;
for(int i=1;i<n;i++){
    if(vec[i]<vec[i-1])
    ans++;
}

cout<<ans;

}