#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int>p(n);
    for(int i=0;i<n;i++)
    {
        cin>>p[i];
    }
    auto it=max_element(p.begin(),p.end());
    int index=it-p.begin();
    int sum=0;
    for(int i=0;i<p.size();i++)
    {
        if(i==index){
            sum+=p[i]/2;
        }
        else
        sum+=p[i];
    }
    cout<<sum;
}