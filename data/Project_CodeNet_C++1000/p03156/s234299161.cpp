#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
struct point{int x;int y;};
int i,j,k,count1=0,count2=0;

int main(){
    int n,a,b;
    cin>>n>>a>>b;
    int x;
    vector<int> vec(3,0);
    rep(i,n){
        cin>>x;
        if(x<=a)vec[0]++;
        if(x>a&&x<=b)vec[1]++;
        if(x>b)vec[2]++;
    }
    sort(vec.begin(),vec.end());
    cout<<vec[0]<<endl;
}