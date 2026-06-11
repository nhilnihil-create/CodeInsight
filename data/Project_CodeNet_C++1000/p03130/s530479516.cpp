#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
struct point{int x;int y;};
int i,j,k,count1=0,count2=0;

int main(){
    vector<int> vec;
    int x;
    rep(i,6){
        cin>>x;
        vec.push_back(x);
    }
    int maxv=count(vec.begin(),vec.end(),1);
    maxv=max(maxv,(int)count(vec.begin(),vec.end(),2));
    maxv=max(maxv,(int)count(vec.begin(),vec.end(),3));
    maxv=max(maxv,(int)count(vec.begin(),vec.end(),4));
    cout<<(maxv>=3?"NO":"YES")<<endl;
}