using namespace std;
#include <bits/stdc++.h>
#include<algorithm>
int main()
{
    int n,a=0;
    cin>>n;
    vector<int>d(n);
    for(int i=0;i<n;i++)cin>>d.at(i);
    
    sort(d.begin(),d.end());
    
    for(int i=0;i<n;i++){
        if(d[i]==d[i+1]){
            a++;
        }
    }
    std::cout << n-a << std::endl;
}
