#include <bits/stdc++.h>
using namespace std;
int main (){
    vector < int > num;
    int a,b,c,n;
    cin>>a>>b>>c;
    cin>>n;
    num.push_back(a);
    num.push_back(b);
    num.push_back(c);
    sort(num.begin(),num.end());
    for(int i=0;i<n;i++){
        num[2] = num[2]*2;
    }
    cout<<num[0]+num[1]+num[2]<<endl;
    return 0;
}