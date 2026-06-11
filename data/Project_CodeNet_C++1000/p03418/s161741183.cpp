#include<iostream>
#include<string>
#include<vector>
#include<algorithm>//sort,reverse
#include<utility>//pair
#include<queue>//queue,priority queue
#include<deque>//double_ended queue
using namespace std;
int main()
{ 
    int n,k;
    cin>>n>>k;
    //i=bとしてaを考える。最大は(k,n)
    long long int ans=0;
    int q=0;//商
    int r=0;//余り
    for(int i=k+1;i<=n;i++){
        q=n/i;
        r=n%i;
        if(k>0){if(r>=k){ans=ans+r-k+1;}}
        else{ans=ans+r;}
        ans=ans+q*(i-k);
    }
    cout<<ans<<endl;
    return 0;
}