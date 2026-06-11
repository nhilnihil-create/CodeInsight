#include <bits/stdc++.h>
using namespace std;
 
int main() 
{
    int a,b,k;
    cin>>a>>b>>k;
    int n = 0;
    vector<int>v(100);
    for(int i = 1; i<=min(a,b); i++){
        if(a % i == 0 && b % i == 0){
            v.at(n) = i;
            n++;
        }
    }
    sort(v.begin(),v.end());
    reverse(v.begin(),v.end());
    cout<<v.at(k - 1)<<endl;
}
