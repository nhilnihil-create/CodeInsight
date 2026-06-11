#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int> l(n);
    for(int i=0;i<n;i++)
    cin>>l[i];
    int max_l=0;
    int64_t sum=0;
    for(int i=0;i<n;i++){
        if(max_l<l[i])
        max_l=l[i];
        sum+=l[i];
    }
    if(sum-max_l>max_l)
    cout<<"Yes"<<endl;
    else
    cout<<"No"<<endl;
}