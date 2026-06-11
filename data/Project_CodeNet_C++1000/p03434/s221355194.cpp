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

vector<int> vec(n);
for(int i=0;i<n;i++)
    cin>>vec[i];
    
sort(vec.begin(), vec.end(), greater<int>());

int al=0, bo=0;
for(int i=0;i<n;i++){
    if(i&1)
    bo+=vec[i];
    else
    al+=vec[i];
}
cout<<al-bo;
    
}