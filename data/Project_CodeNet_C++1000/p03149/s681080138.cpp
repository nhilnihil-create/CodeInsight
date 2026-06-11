#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
struct point{int x;int y;};
int i,j,k,count1=0,count2=0;

int main(){
    vector<int> vec(4);
    vector<int> vec2={1,4,7,9};
    rep(i,4){
        cin>>vec[i];
    }
    sort(vec.begin(),vec.end());
    int ans=1;
    rep(i,4){
        if(vec[i]!=vec2[i])ans=0;
    }
    cout<<(ans?"YES":"NO")<<endl;
}
