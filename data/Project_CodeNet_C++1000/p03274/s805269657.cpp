#include<iostream>
#include<vector>
#include<climits>
using namespace std;
int main(){
    int n,k;
    cin>>n>>k;
    int index=0;
    vector<int>v(n);
    for(int i=0;i<n;i++)
    {
        cin>>v[i];
        if(v[i]<0){
            index=i;
        }
    }
    int startindex=max(index-k,0);
    int endindex=min(index+1,(int)v.size()-1);
    int result=INT_MAX;
    for(int i=startindex;i<=endindex;i++)
    {
        if(i+k-1<v.size()){
            int p=abs(v[i])+abs(v[i+k-1]-v[i]);
            if(result>p){
                result=p;
            }
            p=abs(v[i+k-1])+abs(v[i]-v[i+k-1]);
            if(result>p){;
                result=p;
            }
        }
        
    }
    cout<<result;
}