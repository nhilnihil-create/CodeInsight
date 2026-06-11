#include <bits/stdc++.h>
using namespace std;
struct point{int x;int y;};
int i,j,count1=0,count2=0;

int main(void){
    vector<int> vec(3);
    cin>>vec[0]>>vec[1]>>vec[2];
    sort(vec.begin(),vec.end());
    int def1,def2,ans=0;
    def1=vec[2]-vec[1];
    def2=vec[2]-vec[0];
    if(def1%2==def2%2){
        def2-=def1;
        ans=def1+def2/2;
    }else{
        ans+=def1;
        ans+=(def2-def1+1)/2;
        ans++;
    }
    cout<<ans<<endl;
}