#include <bits/stdc++.h>
using namespace std;



int main() {

    int n;
    cin>>n;


    vector<int> v(n);
    vector<int> c(n);

    for(int i=0;i<n;i++){
        cin>>v.at(i);
    }

    for(int i=0;i<n;i++){
        cin>>c.at(i);
    }

    int x=0,y=0;
    for(int i=0;i<n;i++){
        if(v.at(i)>c.at(i)){
            x+=v.at(i);
            y+=c.at(i);
        }
    }

    cout<<x-y<<endl;

}