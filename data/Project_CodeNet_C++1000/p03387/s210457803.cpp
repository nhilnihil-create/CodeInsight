#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
    vector<int>v(3);
    for(int i=0;i<3;i++)
    {
        cin>>v[i];
    }
    int result=0;
    sort(v.begin(),v.end());
    if(v[0]%2!=v[1]%2){
        v[0]++;
        v[2]++;
        result++;
    }
    result+=(v[2]-v[0])/2;
    if(v[2]%2!=v[0]%2){
        result++;
    }
    result+=(v[2]-v[1])/2;
    cout<<result;
}