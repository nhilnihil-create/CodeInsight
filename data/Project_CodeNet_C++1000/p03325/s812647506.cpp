#include <bits/stdc++.h>
using namespace std;
struct point{int x;int y;};
int i,j,k,count1=0,count2=0;

int main(){
    int n;
    cin>>n;
    vector<int> vec(n);
    int ans=0;
    for(i=0;i<n;i++){
        cin>>vec[i];
        while(vec[i]%2==0){
            ans++;
            vec[i]/=2;
        }
    }
    cout<<ans<<endl;
}