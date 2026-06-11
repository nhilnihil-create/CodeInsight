#include <iostream>
#include<algorithm>
#include<vector>
#include<set>
#include<map>
using namespace std;
int main(void){
    // Your code here!
    int n,k;
    cin>>n>>k;
    
    vector<int> vec(n+1,0);
    for(int i=0;i<n;i++){
        int a;
        cin>>a;
        vec[a]++;
        
    }
    
    vector<int> nv;
     for(int i=0;i<=n;i++){
        if(vec[i]!=0)
            nv.push_back(vec[i]);
        
    }
    
    sort(nv.begin(), nv.end());

int count=0;
    if(nv.size()>k){
        int diff= nv.size()-k;
        int i=0;
        while(diff--){
            count+=nv[i];
            i++;
        }
        cout<<count;
    }else{
        cout<<0;
    } 

}
