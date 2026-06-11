#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    int a1,a2,a3;
    cin>>a1>>a2>>a3;
    int part1 = abs(a1-a2);
    int part2 = abs(a1-a3);
    int part3 = abs(a2-a3);
 
    int maxi = part1>part2?(part1>part3?part1:part3):(part2>part3?part2:part3);
    cout<<maxi<<endl;
    return 0;
}