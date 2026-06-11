#include <bits/stdc++.h>
using namespace std;
 
int main() 
{
    int n,a;
    int al=0;
    int bo=0;
    cin>>n;
    vector<int>v(n);
    for(int i=0; i<n; i++){
        cin>>a;
        v.at(i)=a;
    }
    sort(v.begin(),v.end());
    reverse(v.begin(),v.end());
    for(int k=0; k<n; k++){
        if(k==0 || k%2==0){
            al += v.at(k);
        }else{
            bo += v.at(k);
        }
    }
    cout<<al-bo<<endl;
}