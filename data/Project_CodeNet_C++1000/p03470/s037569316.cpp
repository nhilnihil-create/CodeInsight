#include <bits/stdc++.h>
using namespace std;
 
int main() 
{
    int n,h;
    cin>>n;
    int ans=0;
    vector<int>v(n);
    for(int i=0; i<n; i++){
        cin>>h;
        v.at(i)=h;
        ans++;
        for(int k=0; k<i; k++){
            if(h==v.at(k)){
                ans--;
                break;
            }
        }
    }
    cout<<ans<<endl;
}